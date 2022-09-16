# This is a file I use to test sensehat code (Not in syllabus)
# It contains a similar API to sense_hat, but asks for input for orientation.
# Any messages or pixels it should display are printed to the command line.

def get_input(name):
    for r in range(2):
        try:
            return int(input("Enter a value for " + name + ":"))
        except:
            pass
    print('Exiting Program')
    quit()

class SenseHat:
    board = [0]*64
    rotation = 0
    def get_orientation(self):
        return {'pitch': get_input('pitch'),
                'roll': get_input('roll')}

    def print_board(self):
        print('board:')
        for i in range(0, 64, 8):
            print("[", end="")
            for t in self.board[i:i+7]: self.print_color(t)
            print("]")
        print ("rotation:", self.rotation)

    def print_color(self, t):
        val = [format(i, '03d') for i in t]
        print(val, end='') 

    def set_pixels(self, value):
        self.board = value
        self.print_board()

    def get_pixels(self):
        return self.board

    def get_pixel(self, x, y):
        return self.board[y*8+x]

    def set_pixel(self, x, y, color):
        self.board[8*y + x] = color

    def set_rotation(self, value):
        self.value = value

    def show_message(self, text_string, scroll_speed, text_color, back_color):
        print('text_string:', text_string)
        print('scroll_speed', scroll_speed)
        print('text_color', text_color)
        print('back_color', back_color)
        print('orientation', self.rotation)

