from sense_hat import SenseHat
from time import sleep
from random import randint
sense = SenseHat()

# Default colours, b is black
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
b = (0,0,0)
interval = 1

# Sets pixels to a given color and orientation for an interval.
# If orientation isn't given, the new value is randomised and returned.
def setPixels(color, rotation=-1):
    if rotation == -1:
        rotation = randint(0,3)*90
    c = color
    sense.set_rotation(rotation)
    screen = [b,b,b,b,b,b,b,b,
              b,b,b,b,b,b,c,b,
              b,c,c,c,c,c,c,c,
              b,b,b,b,b,b,b,c,
              b,b,b,b,b,b,b,c,
              b,c,c,c,c,c,c,c,
              b,b,b,b,b,b,c,b,
              b,b,b,b,b,b,b,b]
    sense.set_pixels(screen)
    sleep(interval)
    return rotation

def getRotation():
    # Some code to get the orientation
    pass

# Game starts here
print("The game has started! Can you keep up?")

# Set r to a random orientation of 0-4 (for 90 degree increments)
r = setPixels(blue)

while getRotation() == r:
    setPixels(green, r)
    interval *= 0.95
    r = setPixels(blue)

print("Wrong orientation! You lose!")

# Set pixels to red and end the game
setPixels(red, r)
sense.clear()


