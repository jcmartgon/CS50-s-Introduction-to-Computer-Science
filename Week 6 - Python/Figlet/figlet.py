# Jesus Carlos Martinez Gonzalez
# 13/04/2023
# FIGlet

from pyfiglet import Figlet
import sys
import random


argc = len(sys.argv)
figlet = Figlet()
fonts = figlet.getFonts()

if argc not in [1, 3]:  # Invalid amount of command line arguments
    print("Invalid usage")
    sys.exit(1)
elif argc == 3:  # User inputs a font
    if sys.argv[1] not in ["-f" or "--font"]:  # Wrong flag
        print("Invalid usage")
        sys.exit(1)
    font = sys.argv[2]
    if font not in fonts:  # Invalid font
        print("Invalid usage")
        sys.exit(1)
else:  # Random font
    font = random.choice(fonts)

figlet.setFont(font=font)

text = input("Text: ")

print(figlet.renderText(text))