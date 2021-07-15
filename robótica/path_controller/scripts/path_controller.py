#! /usr/bin/env python
import rospy 
from geometry_msgs.msg import *
from sensor_msgs.msg import *
from nav_msgs.msg import *
import random
import math
from gazebo_msgs.msg import *
import numpy as np
import csv
import rospkg
import matplotlib.pyplot as plt
from matplotlib import cm
import time
from environment import Env
from line import Line

laser = LaserScan()
odometro = Odometry()
line = Line()
LINEAR_VEL = 0.20
ANGULAR_VEL = 0.3
STOP_DISTANCE = 0.35
LIDAR_ERROR = 0.05
SAFE_DISTANCE = STOP_DISTANCE + LIDAR_ERROR



def odom_callback(data):
    global odometro
    odometro = data
    #print(odometro)

def laser_callback(data):
    global laser
    laser = data

def listeners():
    rospy.Subscriber("/odom", Odometry, odom_callback)
    rospy.Subscriber("/scan", LaserScan, laser_callback)

def distanceFront():
    return min(min(laser.ranges[0:17]),min(laser.ranges[342:359]))
def distanceRight():
    return min(laser.ranges[270:305])
def distanceLeft():
    return min(laser.ranges[54:90])
def distanceRightFront():
    return min(laser.ranges[306:341])
def distanceRightBack():
    return min(laser.ranges[210:240])
def distanceLeftFront():
    return min(laser.ranges[18:53])
def distanceLeftBack():
    return min(laser.ranges[120:150])
def jumpOtherWall():
    r = Twist()
    r.linear.x = LINEAR_VEL
    r.angular.z = ANGULAR_VEL*(-1)
    return r
def turnLeft():
    r = Twist()
    r.angular.z = ANGULAR_VEL
    return r
def turnRight():
    r = Twist()
    r.angular.z = ANGULAR_VEL*(-1)
    return r
def walk():
    r = Twist()
    r.linear.x = LINEAR_VEL
    return r
def calculateDistanceBetweenLineAndRobo(roboX,roboY):
    global line    
    up_eq = math.fabs(((line.point2X - line.point1X) * (line.point1Y - roboY)) - ((line.point1X - roboX) * (line.point2Y - line.point1Y)))
    low_eq = math.sqrt(pow(line.point2X - line.point1X, 2) + pow(line.point2Y - line.point1Y, 2))
    return up_eq / low_eq
def calculateAngle(roboX,roboY):
    global line
    dx = roboX - line.point2X
    dy = roboY - line.point2Y
    angle = math.atan2(dy,dx)
    #return angle
    if(angle < 0):
        angle = math.fabs(angle)
    else:
        angle = 2*math.pi - angle
    return math.degrees(angle)

if __name__ == "__main__": 
    rospy.init_node("path_controller_node", anonymous=False)
    listeners()
    
    env = Env()
    state_scan = env.reset()
    action = np.zeros(2)
    bypass = False
    inLine = True
    poolDisLeft = 10.0
    poolDisRight = 10.0

    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)    
    r = rospy.Rate(20) # 10hz
    velocity = Twist()
    goal_aux = env.goal_numbers
    beforeDistanceRightFront = 0.0
    beforeDistanceRight = 10.0
    beforeGoalDistance = 0.0
    mesage = ''
    distanceLine = 0.0
    walkAfterTurn = False
    readLine = True
    stepsTurnWall = 0
    line.setLine(env.position.x, env.position.y, env.goal_x,env.goal_y)

    while not rospy.is_shutdown():
        # FACA SEU CODIGO AQUI

        if(goal_aux != env.goal_numbers):
            goal_aux = env.goal_numbers
            line.setLine(env.position.x, env.position.y, env.goal_x,env.goal_y)
            readLine = True
            stepsTurnWall = 0
        distanceLine = calculateDistanceBetweenLineAndRobo(env.position.x, env.position.y)

        #CODIGO
        if(len(laser.ranges) > 0):
            #goal_angle = math.atan2(env.goal_y - env.position.y,env.goal_x-env.position.x)
            goal_angle = calculateAngle(env.position.x, env.position.y)

            if(readLine and (stepsTurnWall == 0 or stepsTurnWall > 5)):
                if(distanceFront() > SAFE_DISTANCE and distanceRightFront() > SAFE_DISTANCE and distanceLeftFront() > SAFE_DISTANCE and distanceLine <0.3):
                    mesage = "[Line 1] front > safe, right > safe, left > safe == WALK"
                    velocity = walk()
                else:
                    readLine=False
                rospy.loginfo(mesage)
                rospy.loginfo("position x:%s y:%s, goal x:%s y:%s, distancia: %s, heading: %s, angulo: %s", env.position.x, env.position.y, line.point2X, line.point2Y, calculateDistanceBetweenLineAndRobo(env.position.x, env.position.y), env.heading, goal_angle)
                beforeGoalDistance = env.getGoalDistace()
                #pub.publish(velocity)
                action[0] = velocity.linear.x
                action[1] = velocity.angular.z
                state_scan = env.step(action)
            else:
                stepsTurnWall += 1
                if(distanceFront() > SAFE_DISTANCE and distanceRightFront() > SAFE_DISTANCE and distanceLeftFront() > SAFE_DISTANCE and distanceLine <0.3):
                    mesage = "[1] front > safe, right > safe, left > safe == WALK"
                    velocity = walk()
                elif(distanceFront() > SAFE_DISTANCE and distanceRightFront() > SAFE_DISTANCE and distanceLeftFront() > SAFE_DISTANCE and distanceLine > 0.3):
                    mesage = "[10] front > safe, right > safe, left > safe == TURN TO RIGHT"
                    velocity = turnRight()
                #elif(distanceLeft() > SAFE_DISTANCE and distanceLine < 0.3 and goal_angle < -0.1):
                #    mesage = "[11] front < safe, right > safe, left > safe  == TURN TO LEFT"
                #    velocity = turnLeft()
                elif(distanceFront() < SAFE_DISTANCE and distanceRightFront() > SAFE_DISTANCE and distanceLeftFront() > SAFE_DISTANCE):
                    mesage = "[2] front < safe, right > safe, left > safe  == TURN TO LEFT"
                    velocity = turnLeft()
                elif(distanceFront() > SAFE_DISTANCE and distanceRightFront() < SAFE_DISTANCE and distanceLeftFront() > SAFE_DISTANCE):
                    mesage = "[3] front > safe, right < safe, left > safe  == WALK"
                    velocity = walk()
                elif(distanceFront() > SAFE_DISTANCE and distanceRightFront() > SAFE_DISTANCE and distanceLeftFront() < SAFE_DISTANCE):
                    mesage = "[4] front > safe, right > safe, left < safe  == WALK"
                    velocity = walk()
                elif(distanceFront() < SAFE_DISTANCE and distanceRightFront() < SAFE_DISTANCE and distanceLeftFront() > SAFE_DISTANCE):
                    mesage = "[5] front < safe, right < safe, left > safe  == TURN TO LEFT"
                    velocity = turnLeft()
                elif(distanceFront() < SAFE_DISTANCE and distanceRightFront() > SAFE_DISTANCE and distanceLeftFront() < SAFE_DISTANCE):
                    mesage = "[6] front < safe, right > safe, left < safe  == TURN TO RIGHT"
                    velocity = turnRight()
                elif(distanceFront() < SAFE_DISTANCE and distanceRightFront() < SAFE_DISTANCE and distanceLeftFront() < SAFE_DISTANCE):
                    mesage = "[7] front < safe, right < safe, left < safe == TURN TO LEFT"
                    velocity = turnLeft()
                elif(distanceFront() > SAFE_DISTANCE and distanceRightFront() < SAFE_DISTANCE and distanceLeftFront() < SAFE_DISTANCE):
                    mesage = "[8] front > safe, right < safe, left < safe == WALK"
                    velocity = walk()
                else:
                    mesage = "[0] NENHUMA ACAO"
                rospy.loginfo(mesage)
                rospy.loginfo("position x:%s y:%s, goal x:%s y:%s, distancia: %s, heading: %s, angulo: %s", env.position.x, env.position.y, line.point2X, line.point2Y, calculateDistanceBetweenLineAndRobo(env.position.x, env.position.y), env.heading, goal_angle)
                beforeGoalDistance = env.getGoalDistace()
                #pub.publish(velocity)
                action[0] = velocity.linear.x
                action[1] = velocity.angular.z
                state_scan = env.step(action)    

            
            r.sleep()
