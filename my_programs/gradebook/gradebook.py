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
    students, courses = import_data()
    choice = menu()
    actions(choice, students, courses)


def actions(choice, students, courses):
    actions = {
    'p': lambda: print_grades(students),
    'a': lambda: add_student(students, courses),
    # 'r': remove_student,
    # 'g': grade_average,
    # 'q': quit_program
    }

    action = actions.get(choice)
    if action:
        action()
        print()

    menu()


def add_student(students, courses):
    print_grades(students)
    while True:
        name = input("Name of the student you want to add: ").title()
        if name in students:
            print("Student already in gradebook. Please try again.")
        else:
            students[name] = {}
            print()
            break

    print(f"If {name} didn't take course, press enter, else type the grade achieved (0 to 10). ?")
    for course in courses:
        while True:
            grade = input(f"Enter grade for {course}: ")
            try:
                grade = int(grade)
            except ValueError:
                if grade == "":
                    students[name][course] = grade
                    print()
                    break
                else:
                    print("Wrong input. Try again.")
                    continue

            if 0 <= grade <= 10:
                    students[name][course] = grade
                    print()
                    break
            else:
                print("Wrong input. Try again.")


    print_grades(students)

    # for class in students[name]:
    #    print(f"")


    menu()


def menu():
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
        courses = [key for key in file_reader.fieldnames if key != "name"]

        for row in file_reader:
            name = row.pop("name")
            for key in row:
                row[key] = int(row[key])
            students[name] = row

    return students, courses


def print_grades(students):
    print()
    df = pd.DataFrame(students).T
    print(df)
    print()



if __name__ == "__main__":
    main()