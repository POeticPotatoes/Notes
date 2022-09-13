def get_color(color):
    for c in range(3):
        try:
            val = int(raw_input("Enter the value of the " + color + " color for message (0 to 255):"))
        except:
            continue
        if val > -1 and val < 256:
            return val
    return 0
