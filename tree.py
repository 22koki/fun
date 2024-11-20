import turtle
import time
import random

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("sky blue")
screen.title("Growing Tree Animation")

# Create the turtle for drawing
t = turtle.Turtle()
t.speed("fastest")
t.hideturtle()

# Draw the initial seedling
def draw_seedling():
    t.penup()
    t.goto(0, -200)
    t.pendown()
    t.color("saddlebrown")
    t.setheading(90)
    t.forward(50)
    t.left(90)
    t.color("forest green")
    t.begin_fill()
    t.circle(15)
    t.end_fill()

# Animate the growth of the tree
def animate_tree():
    t.penup()
    t.goto(0, -150)
    t.pendown()
    t.color("saddlebrown")
    t.setheading(90)
    
    # Grow the trunk
    for _ in range(15):
        t.forward(10)
        time.sleep(0.1)
        t.clear()
        draw_seedling()  # Redraw the seedling

    # Draw branches and leaves
    t.setheading(90)
    t.forward(100)
    for _ in range(6):  # Number of layers of branches
        t.left(60)
        draw_branch()
        t.right(120)
        draw_branch()
        t.left(60)
        t.penup()
        t.goto(0, -150 + 10 * (_ + 1))  # Move up for next layer
        t.pendown()
        t.setheading(90)
        t.forward(100)

    # Draw fruits and additional details
    draw_fruits()
    draw_birds()
    draw_ground()

def draw_branch():
    t.color("saddlebrown")
    t.pendown()
    t.width(5)
    t.forward(50)
    t.right(90)
    t.color("forest green")
    t.begin_fill()
    draw_leaf()
    t.end_fill()
    t.right(90)
    t.penup()
    t.backward(50)
    t.pendown()
    t.width(3)

def draw_leaf():
    t.circle(20, 180)
    t.left(90)
    t.forward(40)
    t.left(90)
    t.circle(20, 180)
    t.left(90)
    t.forward(40)
    t.right(90)

def draw_fruits():
    t.penup()
    t.color("red")
    for _ in range(10):  # Number of fruits
        x = random.randint(-100, 100)
        y = random.randint(50, 150)
        t.goto(x, y)
        t.pendown()
        t.begin_fill()
        t.circle(10)
        t.end_fill()
        t.penup()

def draw_birds():
    t.penup()
    t.color("black")
    for _ in range(3):  # Number of birds
        x = random.randint(-150, 150)
        y = random.randint(50, 200)
        t.goto(x, y)
        t.pendown()
        t.setheading(45)
        t.begin_fill()
        t.circle(5, 360)
        t.end_fill()
        t.penup()

def draw_ground():
    t.penup()
    t.goto(-300, -200)
    t.pendown()
    t.color("dark green")
    t.begin_fill()
    for _ in range(2):
        t.forward(600)
        t.left(90)
        t.forward(100)
        t.left(90)
    t.end_fill()

# Initial drawing of seedling
draw_seedling()

# Animate the growth of the tree
animate_tree()

# Hide the turtle and finish
t.hideturtle()
turtle.done()
