from sense_hat import SenseHat
from time import sleep
sense = SenseHat()

b = (0,0,0)
w = (255,255,255)
r = (255,0,0)
g = (0,255,0)

board = [[r,r,r,b,b,b,b,r], 
         [r,b,b,b,b,b,b,r],
         [b,b,b,b,g,r,b,r],
         [b,r,r,b,r,r,b,r],
         [b,b,b,b,b,b,b,b],
         [b,r,b,r,r,b,b,b],
         [b,b,b,r,b,b,b,r], 
         [r,r,b,b,b,r,r,r] ]

def move_marble(x,y): # removed extra arguments and added leniency for tilt
    orientation = sense.get_orientation() # modified because get_orientation twice is disgusting
    pitch = orientation['pitch']
    roll = orientation['roll']
    new_x = max(0, min(7, x + (pitch>130) - (pitch<230))) # Exploiting the fact that True=1 and False=0
    new_y = max(0, min(7, y - (roll>1130) + (roll<230))) # Using min and max to prevent overflow

    if check_marble(new_x, new_y): # Do the check here
        print("Bump~")
        return x, y
    return new_x, new_y

def check_marble(x, y):
    return board[y][x] == r

x = 1
y = 1

print("The game has started! Get to the target, quickly!")

while board[y][x] != g: #Reordered the sequence here
    board[y][x] = w
    sense.set_pixels(sum(board,[])) 

    sleep(0.05)
    board[y][x] = b
    x,y = move_marble(x,y)

print("OwO you've won!")
