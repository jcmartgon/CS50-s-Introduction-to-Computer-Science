# Jesus Carlos Martinez Gonzalez
# 12/04/2023
# Bank

greeting = input("Greeting: ").strip()
greeting = greeting[0:5]

if greeting.lower() == "hello":
    score = 0
elif greeting[0].lower() == "h":
    score = 20
else:
    score = 100

print(f'${score}')