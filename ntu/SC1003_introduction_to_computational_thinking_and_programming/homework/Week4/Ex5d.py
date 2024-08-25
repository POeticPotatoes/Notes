from sense_hat import SenseHat
from time import sleep
from random import randint

# Default colors
red = (255,0,0)
green = (0,255,0)
blue = (0,0,255)
b = (0,0,0)

interval = 1

# Sets pixels to a given color and orientation
# If orientation isn't given, the new value is randomised and returned
def setPixels(c, rotation=-1):
    if rotation == -1:
        rotation = randint(0,3)*90
    sense.set_rotation(rotation)
    screen = [b,b,b,b,b,b,b,b,
              b,b,b,b,b,b,c,b,
              b,b,b,b,b,b,c,b,
              b,b,b,b,b,b,c,b,
              b,b,b,b,b,b,c,b,
              b,b,b,b,b,b,c,b,
              b,b,b,b,b,b,c,b,
              b,b,b,b,b,b,b,b]
    sense.set_pixels(screen)
    sleep(interval)
    return rotation

# Returns the orientation in 90 degree increments
def getRotation():
    x,y,z = sense.get_accelerometer_raw()
    if x < -1:
        return 90
    if y < -1:
        return 180
    if x > 1:
        return 270
    return 0

# Game starts here
print("The game has started! Can you keep up?")

# Set r to a random orientation
r = setPixels(blue)

while getRotation() == r:
    setPixels(green, r)
    interval *= 0.9
    r = setPixels(blue)

print("Wrong orientation! You lose!")

interval = 3
setPixels(red, r)
sense.clear()
