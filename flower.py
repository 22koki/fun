import turtle
import random
import time

def draw_stem(t, length, x, y, color):
    t.penup()
    t.goto(x, y)
    t.pendown()
    t.color(color)
    t.setheading(90)
    
    # Animate the stem growth
    for i in range(length):
        t.forward(1)
        time.sleep(0.01)

def draw_petal(t, petal_color):
    t.color(petal_color)
    t.begin_fill()
    for _ in range(2):
        t.circle(20, 60)
        t.left(120)
    t.end_fill()

def draw_flower(t, x, y, petal_color, stem_color):
    draw_stem(t, 100, x, y, stem_color)

    # Move to the top of the stem
    t.penup()
    t.setheading(90)
    t.forward(100)
    t.pendown()

    # Draw and animate each petal
    for _ in range(6):
        draw_petal(t, petal_color)
        t.left(60)

    # Draw the center of the flower
    t.setheading(90)
    t.penup()
    t.forward(20)
    t.pendown()
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

def draw_butterfly(t, x, y):
    t.penup()
    t.goto(x, y)
    t.pendown()
    
    t.color(random.choice(['orange', 'yellow', 'pink', 'blue']))
    t.begin_fill()
    
    # Draw butterfly wings (left)
    t.circle(10, 180)
    t.left(90)
    t.circle(10, 180)
    t.left(90)
    
    # Draw butterfly wings (right)
    t.circle(10, 180)
    t.left(90)
    t.circle(10, 180)
    
    t.end_fill()

def animate_butterflies(t, num_butterflies):
    screen_width = turtle.window_width() // 2
    screen_height = turtle.window_height() // 2

    butterflies = []
    for _ in range(num_butterflies):
        x = random.randint(-screen_width, screen_width)
        y = random.randint(-screen_height, screen_height)
        butterflies.append([x, y])

    for _ in range(200):  # Number of frames
        for butterfly in butterflies:
            x, y = butterfly
            t.clear()
            draw_butterfly(t, x, y)
            butterfly[0] += random.randint(-10, 10)  # Random movement in x
            butterfly[1] += random.randint(-10, 10)  # Random movement in y
            time.sleep(0.05)
        t.clear()

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("sky blue")

# Create turtle
t = turtle.Turtle()
t.speed("fastest")

# Draw the ground
draw_ground(t)

# Draw and animate multiple flowers
colors = ["red", "purple", "blue", "orange", "pink"]
stem_color = "green"
for i in range(5):
    x = random.randint(-200, 200)
    y = -200
    petal_color = random.choice(colors)
    draw_flower(t, x, y, petal_color, stem_color)

# Animate butterflies flying around
animate_butterflies(t, 3)  # Animate 3 butterflies

# Hide the turtle and finish
t.hideturtle()
turtle.done()
