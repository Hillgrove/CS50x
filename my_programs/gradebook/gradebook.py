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
    students, classes = import_data()
    choice = request_input()
    actions(choice)


def actions(choice):
    actions = {
    'p': print_grades,
    'a': add_student,
    # 'r': remove_student,
    # 'g': grade_average,
    # 'q': quit_program
    }

    action = actions.get(choice)
    if action:
        action()
        print()
        request_input()


def add_student(students):
    print_grades()
    while True:
        name = input("Name of the student you want to add: ").title()
        if name in students:
            print("Student already in gradebook. Please try again.")
        else:
            students[name] = {}
            break

    # print_grades()

    # for class in students[name]:
    #    print(f"")


    request_input()


def request_input():
    print("(P)rint grades, (A)dd student, (R)emove student, (G)rade averages, (Q)uit")
    print("Choice: ", end="")
    while True:
        choice = input().lower()
        if choice in ['p', 'a', 'r', 'g', 'q']:
            break
        else:
            print("Invalid choice. Please select from options.")
            print("Choice: ", end="")
    return choice


def import_data():
    students = {}

    filename = sys.argv[1]

    with open(filename, "r") as file:
        file_reader = csv.DictReader(file)
        classes = [key for key in file_reader.fieldnames if key != "name"]

        for row in file_reader:
            name = row.pop("name")
            for key in row:
                row[key] = int(row[key])
            students[name] = row

    return students, classes


def print_grades(students):
    print()
    df = pd.DataFrame(students).T
    print(df)
    print()



if __name__ == "__main__":
    main()