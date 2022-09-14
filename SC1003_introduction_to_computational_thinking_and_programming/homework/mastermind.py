from random import randint

answer = str(randint(0,9999)).zfill(4)
count = [answer.count(str(i)) for i in range(10)]
print("I have a number in mind! Can you guess it?")

guess = str(input("Please input 4 digits:")).zfill(4)[:4]
attempts = 0
while guess != answer:
    attempts += 1
    a = 0
    b = 0
    for i in range(10): b += min(guess.count(str(i)),count[i])
    for i in range(4):
        if guess[i] == answer[i]:
            b -= 1
            a += 1
    print(a, "A (Bulls)", b, "B (Cows)")
    guess = str(input("Please input 4 digits:"))

print("You win!")
print("Attempts:", attempts)
