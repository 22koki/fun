import turtle
import random
import time

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("sky blue")

# Create the turtle for drawing
t = turtle.Turtle()
t.speed("fastest")
t.hideturtle()

# Draw the rocks at the top and bottom
def draw_rocks():
    t.penup()
    t.goto(-150, 150)
    t.pendown()
    t.color("gray")
    t.begin_fill()
    t.forward(300)
    t.left(90)
    t.forward(50)
    t.left(90)
    t.forward(300)
    t.left(90)
    t.forward(50)
    t.left(90)
    t.end_fill()

    # Draw the pool at the bottom
    t.penup()
    t.goto(-150, -150)
    t.pendown()
    t.color("dark blue")
    t.begin_fill()
    t.forward(300)
    t.left(90)
    t.forward(100)
    t.left(90)
    t.forward(300)
    t.left(90)
    t.forward(100)
    t.left(90)
    t.end_fill()

# Animate the waterfall
def animate_waterfall():
    t.penup()
    t.goto(-75, 150)
    t.pendown()
    t.color("light blue")
    t.width(3)

    while True:
        for _ in range(10):  # Number of water streams
            t.penup()
            x_start = random.randint(-75, 75)  # Randomize starting x position
            t.goto(x_start, 150)
            t.pendown()
            length = random.randint(50, 300)  # Randomize length of water stream
            angle = random.randint(85, 95)  # Slight angle variation
            t.setheading(angle)
            t.forward(length)
            draw_splash(t.xcor(), t.ycor())
        t.clear()
        draw_rocks()  # Redraw rocks and pool

# Draw splash effect at the bottom of the waterfall
def draw_splash(x, y):
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.color("light blue")

    for _ in range(3):  # Multiple splashes
        t.begin_fill()
        size = random.randint(5, 15)
        t.circle(size)
        t.end_fill()
        t.penup()
        t.forward(size + 5)
        t.pendown()

# Initial drawing of rocks and pool
draw_rocks()

# Start the waterfall animation
animate_waterfall()

# Hide the turtle and finish
t.hideturtle()
turtle.done()
