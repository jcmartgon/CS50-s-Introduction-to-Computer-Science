# Jesus Carlos Martinez Gonzalez
# 20/04/2023
# Credit


import re
import sys


def main():
    number = get_number()
    if not luhn(int(number)):
        sys.exit("INVALID")
    print(card_type(number))


# Checks if num is syntactically valid
def luhn(num):
    total = 0
    i = 1
    while num >= 1:
        tmp = num % 10
        if i % 2 == 0:
            tmp *= 2
            if tmp > 9:
                total += tmp % 10
                tmp = int(tmp / 10)
        total += tmp
        num = int(num / 10)
        i += 1
    if total % 10 == 0:
        return True
    return False


# Gets and returns a numerical string
def get_number():
    while True:
        num = input("Number: ")
        if num.isnumeric():
            return num


# Check if num matches any of the valid card company patterns
def card_type(num):
    if re.match("^3[47]\d{13}$", num):
        return "AMEX"
    elif re.match("^5[1-5]\d{14}$", num):
        return "MASTERCARD"
    elif re.match("^4\d{12}$", num) or re.match("^4\d{15}$", num):
        return "VISA"
    else:
        return "INVALID"


main()