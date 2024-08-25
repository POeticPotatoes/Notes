from random import randint

answer = str(randint(0,9999)).zfill(4)
count = [0] * 10
for c in answer: count[int(c)] += 1
print("I have a number in mind! Can you guess it?")

guess = str(raw_input("Please input 4 digits:")).zfill(4)[:4]
attempts = 0
while guess != answer:
    attempts += 1
    a = 0
    b = 0
    guess_count = [0] * 10
    for c in guess: guess_count[int(c)] += 1
    for i in range(10): b += min(guess_count[i], count[i])
    for i in range(4):
        if guess[i] == answer[i]:
            b -= 1
            a += 1
    print(a, "A (Bulls)", b, "B (Cows)")
    guess = str(raw_input("Please input 4 digits:"))

print("You win!")
print("Attempts:", attempts)
