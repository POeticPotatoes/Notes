import time
import random

y = (255, 255, 0)
b = (0, 0, 0)

def set_pixels():
    sense.set_rotation(random.randint(0,3)*90)
    image_pixels =	[b, b, b, b, b, b, b, b,
                     b, b, b, y, b, b, b, b,
                     b, b, y, y, y, b, b, b,
                     b, y, b, y, b, y, b, b,
                     b, b, b, y, b, b, b, b,
                     b, b, b, b, y, b, b, b,
                     b, b, b, y, b, b, b, b, 
                     b, b, b, b, b, b, b, b]
    # sense.set_pixels(image_pixels)
    return image_pixels

def random_color():
    return (random.randint(0,255),
            random.randint(0,255),
            random.randint(0,255))


yellow = True
while True:
    time.sleep(1)
    y = (255,255,0) if yellow else (0,0,255)
    # y = random_color()
    print(y, set_pixels())
    yellow = not yellow
