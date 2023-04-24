# Jesus Carlos Martinez Gonzalez
# 22/04/2023
# DNA

import csv
import sys
import regex as re


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read the databse into memory
    db = []
    with open(sys.argv[1]) as f:
        reader = csv.DictReader(f)
        for row in reader:
            for elem in row:
                if elem != 'name':
                    row[elem] = int(row[elem])
            db.append(row)

    # Read the DNA sequence into memory
    seq = ''
    with open(sys.argv[2]) as f:
        seq = f.read()

    # Find longest match of each STR in DNA sequence
    strs = ['AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']
    longest = {str: 0 for str in strs}

    for str in strs:
        longest[str] = longest_match(seq, str)

    # Check database for matching profiles
    for person in db:
        match = True
        for str in strs:
            if str in person:
                if person[str] != longest[str]:
                    match = False
                    break
        if match:
            print(person['name'])
            return

    print('No match')

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
