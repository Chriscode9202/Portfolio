import random

rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

#Write your code below this line 👇


game = [rock, paper, scissors]
user_choice = int(input("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors.\n"))
if user_choice >= 3 or user_choice < 0:
  print("Try again")
else:
  print(game[user_choice])

  computer_choice = random.randint(0, 2)
  print("Computer chose:\n")
  print(game[computer_choice])


  if user_choice == computer_choice:
    print("Tie")
  elif user_choice == 0 and computer_choice == 1:
    print("Loser")
  elif user_choice == 0 and computer_choice == 2:
    print("Winner")
  elif user_choice == 1 and computer_choice == 0:
    print("Winner")
  elif user_choice == 1 and computer_choice == 2:
    print("Loser")
  elif user_choice == 2 and computer_choice == 0:
    print("Loser")
  elif user_choice == 2 and computer_choice == 1:
    print("Winner")
  else:
    print("Invalid input you loose")
