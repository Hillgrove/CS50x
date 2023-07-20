import csv
import requests


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
    new_cases = {}
    previous_cases = {}

    for row in reader:
        if row["state"] not in new_cases:
            new_cases[row["state"]] = [int(row["deaths"])]
            previous_cases[row["state"]] = [int(row["deaths"])]

        else:
            new_cases[row["state"]].append(int(row["deaths"]) - previous_cases[row["state"]][0])
            previous_cases[row["state"]] = [int(row["deaths"])]

        if len(new_cases[row["state"]]) > 14:
            new_cases[row["state"]].pop(0)

    return new_cases


# Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        first_week_average = sum(new_cases[state][:7]) / 7  # 15,71
        last_week_average = sum(new_cases[state][7:]) / 7   # 6,57

        try:
            comparative_average = (last_week_average - first_week_average) / first_week_average * 100

        except ZeroDivisionError:
            comparative_average = 0

        print(f"{state} had a 7-day average of {last_week_average:.2f} and {'an increase' if comparative_average >= 0 else 'a decrease'} of {abs(comparative_average):.2f}%.")


main()
