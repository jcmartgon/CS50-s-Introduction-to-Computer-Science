# Jesus Carlos Martinez Gonzalez
# 14/04/2023
# Seven Day Average

import csv
import requests
from datetime import datetime  # Work with dates


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):

    new_cases = dict()
    previous_cases = dict()
    states = []
    dates = []
    reader_copy = []

    # Iterate over 'reader', populate the states' and 'dates' lists and create a copy of reader
    for entry in reader:
        states.append(entry['state'])
        dates.append(entry['date'])

        reader_copy.append(entry)

    states = list(set(states))  # Remove duplicates from states
    start_date = dates[0]  # First recorded date in 'reader'

    # Populate 'previous_cases' and 'new_cases' with their corresponding original data
    for state in states:
        previous_cases[state] = {'date': start_date, 'cases': 0}
        new_cases[state] = []

    for entry in reader_copy:
        date = entry["date"]
        state = entry["state"]
        cases = int(entry["cases"])

        # Calculate how many days have passed since the last entry for 'state'
        skipped = days_between(date, previous_cases[state]['date']) - 1

        # Handles initial scenario where 'start_date' and 'date' are the same
        if skipped < 0:
            skipped = 0

        new_cases[state].extend([0 for i in range(skipped)])  # Appends a 0 to the state's cases list for each skipped day
        new_cases[state].append(cases - previous_cases[state]['cases'])  # Apppends the latest entry

        # Updates 'previous_cases'
        previous_cases[state]['date'] = date
        previous_cases[state]['cases'] = cases

        # If there's more than 14 entries, remove the oldest
        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)
    return new_cases


# Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        latest_avg = get_avg(new_cases[state][7:15])  # Average of the last 7 days
        previous_avg = get_avg(new_cases[state][0:7])  # Average of the 7 days before ^

        try:
            comp_avg = (latest_avg - previous_avg) / previous_avg
        except ZeroDivisionError:
            comp_avg = 0.0

        print(f'{state} had a 7-day average of {latest_avg:.2f} and an increase of {(comp_avg * 100):.2f}%.')


# Returns the days between d1 and d2
def days_between(d1, d2):
    d1 = datetime.strptime(d1, "%Y-%m-%d")
    d2 = datetime.strptime(d2, "%Y-%m-%d")
    return (d2 - d1).days


# Returns average of elements in lst
def get_avg(lst):
    try:
        return sum(lst) / len(lst)
    except ZeroDivisionError:
        return 0.0


main()