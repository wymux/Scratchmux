import random as rnd
    
def guessing_game():
    ans = rnd.randint(0, 100)
    guess = int(input('\nGuess random number between 0 and 100\n'))
    
    while (guess != ans):
        if (guess > ans):
            print(f"User guess is above answer.\n")
        else:
            print(f"User guess is below answer.\n")
        guess = int(input('Guess random number between 0 and 100\n'))
        
    print(f"You guess correctly: {ans}")

guessing_game()
