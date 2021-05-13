#! /usr/bin/env python

from pickle import FALSE, TRUE
import rospy 
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
import numpy as np
import math

class Environment():
    def __init__(self):
        rospy.Subscriber('/odom', Odometry, self.odometry_callback)
        rospy.Subscriber('/base_scan', LaserScan, self.laser_callback)
        self.pub_cmd_vel = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
        self.odometry = Odometry()
        self.laser = LaserScan()
        self.position_robot_x = 0.
        self.position_robot_y = 0.
        rospy.sleep(1)
        
        
    def odometry_callback(self, data):
        self.odometry = data
        self.position_robot_x = data.pose.pose.position.x
        self.position_robot_y = data.pose.pose.position.y
    
    def laser_callback(self, data):
        self.laser = data
    
    def step(self, action):
        linear_vel = action[0]
        ang_vel = action[1]
        
        vel_cmd = Twist()
        vel_cmd.linear.x = linear_vel
        vel_cmd.angular.z = ang_vel
        
        self.pub_cmd_vel.publish(vel_cmd)
        
    def shutdown(self):
        rospy.loginfo("Lugar alcancado!!! o/ \o")
        self.pub_cmd_vel.publish(Twist())
        

if __name__ == "__main__":
    rospy.init_node('work_controller_node', anonymous=False)
    
    env = Environment()
    
    target_x = -3.0
    target_y = 5.0
    
    min_distance = 0.3

    distance_before_right = 0.0
    distance_before_left = 0.0
    x_ok = 0
    
    action = np.zeros(2)
    
    r = rospy.Rate(10)
    
    while not rospy.is_shutdown():
        
        x_robot = env.position_robot_x
        y_robot = env.position_robot_y
        
        distance_robot = math.sqrt((x_robot - target_x)**2 + (y_robot - target_y)**2)
        
        if distance_robot > min_distance:
            rospy.loginfo('Aonde estou: X--> %s, Y--> %s, range: 90-180--> %f  180-225--> %f 0-90-->%f', x_robot, y_robot, max(env.laser.ranges[90*4:180*4]),max(env.laser.ranges[180*4:225*4]),max(env.laser.ranges[45*4:90*4]))
            if (min(env.laser.ranges[90*4:180*4]) < 0.3):
                rospy.loginfo('range: 90-180--> %f  180-225--> %f 0-90-->%f', min(env.laser.ranges[90*4:180*4]),min(env.laser.ranges[180*4:225*4]),min(env.laser.ranges[45*4:90*4]))
                if(max(env.laser.ranges[180*4:225*4]) < max(env.laser.ranges[0*4:90*4])):
                    action[0] = 0.
                    action[1] = -90.0
                else:
                    action[0] = 0.
                    action[1] = 90.0
            else:
                if ((min(env.laser.ranges[180*4:225*4]) - distance_before_left) > 0.8 ):
                    action[0] = 0.
                    action[1] = 90.0
                else:
                    distance_before_right = min(env.laser.ranges[45*4:90*4])
                    distance_before_left = min(env.laser.ranges[180*4:225*4])
                    rospy.loginfo('distancia: direita--> %f  esquerda--> %f',distance_before_right,distance_before_left)
                    action[0] = 0.3
                    action[1] = 0.0
            
            env.step(action)
        else:
            env.shutdown()
            
        r.sleep()
