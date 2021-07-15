#! /usr/bin/env python
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import *
from gazebo_msgs.msg import *
from sensor_msgs.msg import *
from nav_msgs.msg import *
import random
from environment import Env
import numpy as np
from line import Line
import math

position = Pose()
laser = LaserScan()
odometro = Odometry()
env = Env()
line = Line()

pub = rospy.Publisher("cmd_vel", Twist, queue_size=10)

velocity = Twist()

LINEAR_VEL = 0.22
ANGULAR_VEL = 0.5
STOP_DISTANCE = 0.3
LIDAR_ERROR = 0.05
SAFE_STOP_DISTANCE = STOP_DISTANCE + LIDAR_ERROR

def position_callback(data):
    global position
    position = data.pose[-1]
    #print(position)

def laser_callback(data):
    global laser
    laser = data
    #print(len(laser.ranges))

def odom_callback(data):
    global odometro
    odometro = data

def createNode():
    rospy.init_node('turtlebot3_node', anonymous=False)

def listeners():
    rospy.Subscriber("/gazebo/model_states", ModelStates, position_callback)
    rospy.Subscriber("/scan", LaserScan, laser_callback)
    rospy.Subscriber("/odom", Odometry, odom_callback)

def walk():
    rospy.loginfo("#### WALKING ####")
    velocity.linear.x = LINEAR_VEL
    velocity.angular.z = 0.0
    pub.publish(velocity)

def turnRight():
    rospy.loginfo("#### TURN RIGHT ####")
    velocity.linear.x = 0.0
    velocity.angular.z = ANGULAR_VEL
    pub.publish(velocity)

def turnLeft():
    rospy.loginfo("#### TURN LEFT ####")
    velocity.linear.x = 0.0
    velocity.angular.z = ANGULAR_VEL*(-1)
    pub.publish(velocity)

def calculateDistanceBetweenLineAndRobo(roboX,roboY):
    global line    
    up_eq = math.fabs(((line.point2X - line.point1X) * (line.point1Y - roboY)) - ((line.point1X - roboX) * (line.point2Y - line.point1Y)))
    low_eq = math.sqrt(pow(line.point2X - line.point1X, 2) + pow(line.point2Y - line.point1Y, 2))
    return up_eq / low_eq
    

def distanceFront():
    global laser
    return min(min(laser.ranges[0:50]),min(laser.ranges[310:359]))
    
def publishers():
    
    change_strategy = False
    interaction_size = 12
    reverse_direction = 1
    multiplier_interaction = 1
    odd=True
    before_distance = []
    r = rospy.Rate(10)
    odomX = []
    odomY = []
    env = Env()
    state_scan = env.reset()
    action = np.zeros(2)
    line.setLine(env.position.x, env.position.y, env.goal_x,env.goal_y)

    while not rospy.is_shutdown():

        goal_angle = math.atan2(env.goal_y - env.position.y,env.goal_x-env.position.x)
        rospy.loginfo("##### ALVO %s x: %s y: %s ## ROBO x: %s y: %s ## DISTANCIA: %s ## ANGULO %s ## HEADING %s", env.goal_numbers, env.goal_x,env.goal_y, env.position.x, env.position.y, calculateDistanceBetweenLineAndRobo(env.position.x,env.position.y), goal_angle, env.heading)
        

        if(len(laser.ranges) > 0):
            if(min(laser.ranges[0:90]) > 0.5 or min(laser.ranges[270:360]) > 0.5):
                velocity.linear.x = random.uniform(0.1,0.25)
                velocity.angular.z = 0
            else:
                velocity.linear.x = 0
                velocity.angular.z = 0.2
            pub.publish(velocity)


        #if (min(state_scan[:20]) > 0.25):
        #    action[0] = .0
        #    action[1] = 0.
        #else:
        #    action[0] = 0.
        #    action[1] = 0.0
            
        #state_scan = env.step(action)
        r.sleep()

if __name__ == "__main__":
    createNode()
    listeners()
    publishers()
    #rospy.spin()