# Jesus Carlos Martinez Gonzalez
# 21/04/2023
# Readability


def main():
    text = input("Text: ")
    print(grade(text))


# Coleman-Liau formula
def grade(text):

    letters = words = sentences = 0

    # Gets proper values from text
    for char in text:
        if char in ['.', '?', '!']:
            sentences += 1
        elif char == ' ':
            words += 1
        elif char.isalpha():
            letters += 1
    words += 1  # Accounts for last word (which isn't delimited by a blank space)

    L = (letters * 100) / words
    S = (sentences * 100) / words
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    # Output
    if grade >= 16:
        return 'Grade 16+'
    elif grade < 1:
        return 'Before Grade 1'
    return f'Grade: {grade}'


main()