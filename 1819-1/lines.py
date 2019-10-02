#!/bin/python3

import turtle
import math

turtle.setworldcoordinates(0, 0, 400, 400)
turtle.speed(5000)
def line(p1, p2):
    turtle.speed(500)
    turtle.penup()
    turtle.goto(p1)
    turtle.pendown()
    turtle.goto(p2)
# def par_simple(scale, no_lines):
#     for x in  range(0, no_lines+1):
#         line((0, scale*(no_lines-x)/no_lines), (scale*x/no_lines, 0))

# # par_simple(300, 150)


def par(scale, no_lines, mul_1, mul_2, it):
    for x in it:
        line((0, mul_1*scale*(no_lines-x)/no_lines), (mul_2*scale*x/no_lines, 0))

par(150, 150, 1, 1.25, range(0, 150, 2))
par(150, 150, 1.25, 1, range(150, 0, -2))

turtle.exitonclick()