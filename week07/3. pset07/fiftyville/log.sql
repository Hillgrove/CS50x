-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Finds crimereports
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";
/*
Knowledge gained:
    reportID is 295
    theft done at 10:15am
    3 witnesses
    all reports mentions bakery
 */

-- Finds interviews mentioning "bakery"
SELECT * from interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";
/*
Knowledge gained:
    within 10 mins of theft, thief drove away from parking lot
    Thief withdrew money from ATM on leggett Street earlier same morning
    Thief called someone for less than a minute while leaving the bakery
    Thief planning to take earliest flight out of Fiftyville tomorrow
    Person on the other end to purchase ticket
*/

-- Finds names of all who made a withdrawal the given day and location
SELECT DISTINCT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

SELECT name

+---------+
|  name   |
+---------+
| Bruce   |
| Diana   |
| Brooke  |
| Kenny   |
| Iman    |
| Luca    |
| Taylor  |
| Benista |
+---------+



-- Finds the names of all who owns a car that exited the parkinglot between 10:15 and 10:25
SELECT people.name FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate WHERE year =2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = "exit";
+---------+
|  name   |
+---------+
| Vanessa |
| Bruce   |
| Barry   |
| Luca    |
| Sofia   |
| Iman    |
| Diana   |
| Kelsey  |
+---------+


