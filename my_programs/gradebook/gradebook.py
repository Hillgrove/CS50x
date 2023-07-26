"""
Student Gradebook:
Create a list of dictionaries where each dictionary represents a student.
The dictionaries should contain keys like 'name', 'grade', and 'class'.
Write functions to add a student, remove a student, and calculate the
average grade of the class.
"""

import csv
import sys

import pandas as pd


def main():
    students = import_data()

    choice = input(f"(P)rint grades, (A)dd student, (R)emove student, (G)rade averages, (Q)uit: ").lower()
    while True:
        if choice in ['p', 'a', 'r', 'g', 'q']:
            break
        else:
            print("Invalid choice. Please select from options.")
            continue




def import_data():
    students = []
    filename = sys.argv[1]

    with open(filename, "r") as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            for key in row:
                if key != "name":
                    row[key] = int(row[key])
            students.append(row)

    return students


def print_all_grades(students):
    df = pd.DataFrame(students)
    print(df)

if __name__ == "__main__":
    main()