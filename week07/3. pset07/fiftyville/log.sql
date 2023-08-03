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

-- Finds all withdrawals the given day and location
SELECT DISTINCT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
+----------------+ 
| account_number |
+----------------+
| 28500762       |
| 28296815       |
| 76054385       |
| 49610011       |
| 16153065       |
| 25506511       |
| 81061156       |
| 26013199       |
+----------------+

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

SELECT people.name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw";


/*
Knowledge gained:
    list of account numbers and amount withdrawn
*/




-- Finds all license plates that exited the parkinglot between 10:15 and 10:25
SELECT license_plate FROM bakery_security_logs WHERE year =2021 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25 AND activity = "exit";/*
Knowledge gained:
    list of license plates
*/

