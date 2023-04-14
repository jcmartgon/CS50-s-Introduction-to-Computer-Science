# Figlet

## Problem Description

### Background

FIGlet, named after Frank, Ian, and Glen’s letters, is a program from the early 1990s for making large letters out of ordinary text, a form of ASCII art:

 ![Example](./Resources/Reference.png)

Among the fonts supported by FIGlet are those at figlet.org/examples.html.

FIGlet has since been ported to Python as a module called pyfiglet.

In a file called figlet.py, implement a program that:

Expects zero or two command-line arguments:
Zero if the user would like to output text in a random font.
Two if the user would like to output text in a specific font, in which case the first of the two should be -f or --font, and the second of the two should be the name of the font.
Prompts the user for a str of text.
Outputs that text in the desired font.
If the user provides two command-line arguments and the first is not -f or --font or the second is not the name of a font, the program should exit via sys.exit with an error message.

## My solution

### Description

Import Figlet, validate user input and render the output as per the documentation.

```python
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
```
## Output Expected

![OutputExpected](Resources/OutcomeExpected.png)

## Output Obtained

![As expected](Resources/OutcomeObtained.png)

## Score

![All good](./Resources/Score.png)

## Usage

1. Run 'python figlet.py -f font' on your command line and follow the prompt. (Flag and font are optional, but must be used together)