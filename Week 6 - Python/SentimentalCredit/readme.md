# Credit

## Problem Description

### Background

A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

#### Luhn's Algorithm:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

### Implementation Details

In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading zeroes. But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input.

## My solution

- luhn

```python
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
```

- card_type

```python
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
```

## Output Expected

![Output expected](./Resources/OutputExpected.png)

## Output Obtained

![As expected](./Resources/OutputObtained.png)

## Score

![All good](./Resources/Score.png)

## Usage

1. Run 'python credit.py' on your command line and follow the prompt.