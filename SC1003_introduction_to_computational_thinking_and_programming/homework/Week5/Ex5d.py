import time
import random

b = (0, 0, 0)
r = (255, 0, 0)
g = (0, 255, 0)

def set_pixels(rotation, y):
    image_pixels =	[b, b, b, b, b, b, b, b,
                     b, b, b, b, b, b, y, b,
                     b, b, y, y, y, y, y, b,
                     b, b, b, b, b, b, y, b,
                     b, b, b, b, b, b, y, b,
                     b, b, y, y, y, y, y, b,
                     b, b, b, b, b, b, y, b,
                     b, b, b, b, b, b, b, b]
    # sense.set_pixels(image_pixels)
    return image_pixels

while True:
    rotation = random.randint(0,3)
    set_pixels(rotation*90, (0,0,255))
    
    sleep(1)
    x = sense.get_accelerometer_raw()['x']

    130 -> 90
    210 -> 180
    250 -> 270
    350 -> 0

    (130+45)//90%4

