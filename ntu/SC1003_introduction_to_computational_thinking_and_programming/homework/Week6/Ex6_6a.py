from sense_hat import SenseHat
from time import sleep
sense = SenseHat()

b = (0,0,0)
w = (255,255,255)
r = (255,0,0)
g = (0,255,0)

# Adjust leniency to change how much you need to tilt to move the marble
leniency = 50
high = 180+leniency
low = 180-leniency

board = [[r,r,r,b,b,b,b,r], 
         [r,b,b,b,b,b,b,r],
         [b,b,b,b,g,r,b,r],
         [b,r,r,b,r,r,b,r],
         [b,b,b,b,b,b,b,b],
         [b,r,b,r,r,b,b,b],
         [b,b,b,r,b,b,b,r], 
         [r,r,b,b,b,r,r,r] ]

# Same function as defined in the tutorial, but with optimisations.

def move_marble(x,y): # removed extra arguments for oreintation
    orientation = sense.get_orientation() # doing get_orientation twice is disgusting
    pitch = orientation['pitch']
    roll = orientation['roll']
    new_x = max(0, min(7, x + (pitch>high) - (pitch<low))) # Exploiting the fact that True=1 and False=0
    new_y = max(0, min(7, y - (roll>high) + (roll<low))) # Using min and max to prevent overflow

    # Check if the new location is free, if not cancel the movement
    if check_marble(new_x, new_y):
        print("Bump~")
        return x, y

    return new_x, new_y

# Checks if a location is free
def check_marble(x, y):
    return board[y][x] == r

# Starting coordinates of the marble
x = 1
y = 1

print("The game has started! Get to the target, quickly!")

while board[y][x] != g:
    # Haven't won yet, update marble position
    board[y][x] = w
    sense.set_pixels(sum(board,[])) 
    sleep(0.05)

    # Try to get a new marble position
    board[y][x] = b
    x,y = move_marble(x,y)

print("OwO you've won!")
