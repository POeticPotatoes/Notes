password = ''

while True:
    password = input("Please input a password.")

    if len(password) < 8:
        print("Your password must be more than 8 characters.")
        continue
    if password.isupper():
        print("Your password needs lowercase letters.")
        continue
    if password.islower():
        print("Your password needs uppercase letters")
        continue
    break;

print("Password saved!")
