"""
Student Gradebook:
Create a list of dictionaries where each dictionary represents a student.
The dictionaries should contain keys like 'name', 'grade', and 'class'.
Write functions to add a student, remove a student, and calculate the
average grade of the class.
"""

import csv
import sys


def main():
    students = []
    filename = sys.argv[1]

    with open(filename, "r") as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            row["math"] = int(row["math"])
            row["english"] = int(row["english"])
            row["computer science"] = int(row["computer science"])
            students.append(row)

    for student in students:
        for class_name, grade in student.items():
            print(f"{class_name}: {grade}")
        print("\n")


if __name__ == "__main__":
    main()