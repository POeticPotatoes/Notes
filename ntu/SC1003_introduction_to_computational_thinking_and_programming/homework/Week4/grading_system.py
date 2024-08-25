# Initialise an empty dictionary of groups (this is my class)
groups = {}

# First function to print groups
def print_groups():
    print(groups)

# Second function to save grades
def enter_grade(database, group, id, score):
    # If the group doesn't exist yet, create it and set all the students' scores to 0 first
    if not group in database:
        database[group] = [0]*40
    # Put the student's score inside the group
    database[group][index-1] = score
    print("Score of student was saved!")


# The main body of the program, where the functions are called
while True:
    print("Welcome to the class management system!")
    print("[1] Print all grades")
    print("[2] Input a grade")
    print("[q] quit")
    action = input("What do you want to do?: ")

    if action == '1':
        # Call the group printing function
        print_groups()
        continue
    if action == '2':
        # Get values from the user
        group = input("What group is the student in?")
        index = int(input("What index is the student?"))
        score = int(input("What score did the student get?"))
        # Call the grade entering function
        enter_grade(groups, group, index, score)
        continue
    if action == 'q':
        break
    print("Input a valid action!")
