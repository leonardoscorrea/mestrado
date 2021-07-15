#! /usr/bin/env python
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import *
from gazebo_msgs.msg import *
from sensor_msgs.msg import *
from nav_msgs.msg import *
import random
from environment import Env

position = Pose()
laser = LaserScan()
odometro = Odometry()
env = Env()

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

    while not rospy.is_shutdown():

        if(len(laser.ranges) > 0):
            before_distance.append(env.getGoalDistace())
            odomX.append(odometro.pose.pose.position.x)
            odomY.append(odometro.pose.pose.position.y)
            if(len(before_distance) > 20):
                distance_x = odomX[len(odomX)-1] - odomX[0]
                distance_y = odomY[len(odomY)-1] - odomY[0]
                rospy.loginfo("ODON X[0]: %s X[n]: %s == Y[0]: %s Y[n]: %s", odomX[0],odomX[len(odomX)-1],odomY[0],odomY[len(odomY)-1])
                rospy.loginfo("DISTANCIA %s a %s - DISTANCIA ODON X: %s DISTANCIA ODON Y: %s", before_distance[0],before_distance[len(before_distance)-1], distance_x,distance_y)
                
                if(before_distance[0] <= before_distance[len(before_distance)-1]): #verifica se esta se afastando
                    rospy.loginfo("#### ALTERA ESTRATEGIA ####")
                    change_strategy=True
                else:
                    change_strategy=False
                before_distance = []
                odomX = []
                odomY = []

            if(change_strategy):

                #if(odomX[0] < odomX[len(odomX) - 1] and odomY[0] -)

                rospy.loginfo("#### ALTERANDO ESTRATEGIA ####")
                #uma interacao sentido horario, outra sentido anti-horario
                #for x in range(1,(interaction_size*multiplier_interaction)): #positivo gira sentido anti-horario, negativo sentido horario
                for x in range(1,interaction_size): # vira sentido anti-horario
                    turnLeft()

                for x in range(1,interaction_size): #anda um pouco
                    walk()
                    before_distance.append(env.getGoalDistace())
                
                if(before_distance[0] <= before_distance[len(before_distance)-1]): #verifica se aumentou a distancia 
                    for x in range(1,(interaction_size*2)): #se aumentou a distancia, inverte o lado de giro
                        turnRight()
                before_distance=[]

                change_strategy=False
                rospy.loginfo("#### FIM DA ALTERACAO DE ESTRATEGIA ####")
            else:
                if(min(laser.ranges[0:50]) > SAFE_STOP_DISTANCE and min(laser.ranges[310:359]) > SAFE_STOP_DISTANCE):
                    walk()
                else:
                    if(min(laser.ranges[0:60]) >= min(laser.ranges[300:359])):
                        for x in range(1,interaction_size):
                            turnRight()
                    else:
                        for x in range(1,interaction_size):
                            turnLeft()
                    
                pub.publish(velocity)
            


        #velocity.linear.x = 0.1
        #velocity.linear.x = random.uniform(0.1,0.25)
        #rospy.loginfo("Velocity %s m/s, angular %s , alvo: %s", velocity.linear.x, velocity.angular.z, env.getGoalDistace())
        #pub.publish(velocity)
        r.sleep()

if __name__ == "__main__":
    createNode()
    listeners()
    publishers()
    #rospy.spin()