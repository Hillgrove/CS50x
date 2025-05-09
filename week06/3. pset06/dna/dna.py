import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable, converting numbers to integers
    database = []
    with open(sys.argv[1], "r") as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            for key, value in row.items():
                if key != "name":
                    row[key] = int(value)
            database.append(row)

        # Read fieldnames into a variable
        fieldnames = file_reader.fieldnames
        # Dict-comprehension curtesy of duck debugger
        subsequences = {fieldname: 0 for fieldname in fieldnames if fieldname != "name"}

    # print(database)
    # print(subsequences)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        sequence = file.read()

    # print(sequence)

    # Find longest match of each STR in DNA sequence
    for subsequence in subsequences:
        subsequences[subsequence] = longest_match(sequence, subsequence)

    # print(subsequences)

    # Check database for matching profiles
    matching_person = "No match"
    for person in database:
        # Generator expression curtesy of duck  debugger
        if all(person[key] == value for key, value in subsequences.items()):
            matching_person = person["name"]
            break

    print(matching_person)


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
