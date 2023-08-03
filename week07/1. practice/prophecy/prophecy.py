import csv

from cs50 import SQL


def main():
    # Open database
    db = SQL("sqlite:///prophecy.db")

    # Drop tables
    db.execute("DROP TABLE IF EXISTS students")
    db.execute("DROP TABLE IF EXISTS  houses")
    db.execute("DROP TABLE IF EXISTS  assignments")

    # Create tables
    db.execute(
        """
        CREATE TABLE students (
           id INTEGER NOT NULL,
           student_name TEXT NOT NULL,
           PRIMARY KEY(id)
        );
    """
    )

    db.execute(
        """
        CREATE TABLE houses (
            id INTEGER NOT NULL,
            house TEXT UNIQUE NOT NULL,
            head TEXT NOT NULL,
            PRIMARY KEY(id)
        );
    """
    )

    db.execute(
        """
        CREATE TABLE assignments (
            id INTEGER NOT NULL,
            student_id INTEGER NOT NULL,
            house_id INTEGER NOT NULL,
            PRIMARY KEY(id)
            FOREIGN KEY(student_id) REFERENCES students(id)
            FOREIGN KEY(house_id) REFERENCES houses(id)
        );
    """
    )

    #Open CSV file
    with open("students.csv", "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            db.execute("INSERT INTO students(student_name) VALUES (?)", (row["student_name"],))
            db.execute("INSERT OR IGNORE INTO houses (house, head) VALUES (?, ?)", (row["house"],), (row["head"],))
            db.execute("INSERT INTO assignments (student_id, house_id) VALUES ((SELECT id FROM students WHERE student_name = ?), (SELECT id from houses WHERE house = ?))", (row["student_name"],), (row["house"],))



    # students = db.execute("SELECT * FROM students WHERE house LIKE ?", house)

    # for student in students:
    #    print(student["student_name"])


if __name__ == "__main__":
    main()
