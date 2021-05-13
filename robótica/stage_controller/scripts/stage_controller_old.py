#!/usr/bin/python
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import *
from sensor_msgs.msg import *
from nav_msgs.msg import *
import time
import random

laser = LaserScan()
odometry = Odometry()

def odometry_callback(data):
    global odometry
    odometry = data

def laser_callback(data):
    global laser
    laser = data

def readInformation():
    rospy.Subscriber('/odom', Odometry, odometry_callback)
    rospy.Subscriber('/base_scan', LaserScan , laser_callback)

def publishInformation():
    global laser
    global odometry
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    r = rospy.Rate(5)
    velocity = Twist()
    while not rospy.is_shutdown():
        x = odometry.pose.pose.position.x
        y = odometry.pose.pose.position.y
        rospy.loginfo("Posicao x: %s, Posicao y: %s", x, y)

        #primeira vez que roda a lista esta vazia, entao precisa encher essa lista
        if(len(laser.ranges) > 0):
            #if(min(laser.ranges) > 0.5):
            #cada grau tem 4 valores, entao pegando a quantidade de graus x4 pra limitar
            if(min(laser.ranges[90*4:225*4]) > 0.5):
                #velocity.linear.x = 0.2
                #velocity.angular.z = 0
                velocity.linear.x = random.uniform(0.2,0.5)
                velocity.angular.z = random.uniform(-0.25,0.25)
            else:
                velocity.linear.x = 0
                velocity.angular.z = 0.2
            
            pub.publish(velocity)

        print(len(laser.intensities))
        r.sleep()

def createNode():
    rospy.init_node('stage_controller_node', anonymous=False)

if __name__ == "__main__":
    createNode()
    readInformation()
    publishInformation()
    #rospy.spin()