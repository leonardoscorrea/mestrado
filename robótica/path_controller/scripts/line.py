#!/usr/bin/env python

class Line:
    
    def __init__(self):
        self.point1X = 0.0
        self.point1Y = 0.0
        self.point2X = 0.0
        self.point2Y = 0.0

    def setLine(self,point1X,point1Y,point2X,point2Y):
        self.point1X = point1X
        self.point1Y = point1Y
        self.point2X = point2X
        self.point2Y = point2Y
