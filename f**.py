import turtle
import random

def draw_flower(t, x, y, petal_color, stem_color):
    # Move turtle to position
    t.penup()
    t.goto(x, y)
    t.pendown()
    
    # Draw stem
    t.color(stem_color)
    t.setheading(90)  # Face upwards
    t.forward(100)  # Length of the stem

    # Draw petals
    t.color(petal_color)
    for _ in range(6):  # Drawing 6 petals
        t.circle(20, 60)  # Draw a petal
        t.left(120)       # Position for the next petal
        t.circle(20, 60)
        t.left(60)

    # Draw the center of the flower
    t.setheading(90)
    t.forward(20)
    t.color('yellow')
    t.begin_fill()
    t.circle(10)
    t.end_fill()

def draw_ground(t):
    t.penup()
    t.goto(-300, -250)
    t.pendown()
    t.color("green")
    t.begin_fill()
    for _ in range(2):
        t.forward(600)
        t.left(90)
        t.forward(100)
        t.left(90)
    t.end_fill()

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("sky blue")

# Create turtle
t = turtle.Turtle()
t.speed("fastest")

# Draw the ground
draw_ground(t)

# Draw multiple flowers
colors = ["red", "purple", "blue", "orange", "pink"]
stem_color = "green"
for i in range(5):
    x = random.randint(-200, 200)
    y = -200
    petal_color = random.choice(colors)
    draw_flower(t, x, y, petal_color, stem_color)

# Hide the turtle and finish
t.hideturtle()
turtle.done()
