-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Finds crimereports
SELECT
  *
FROM
  crime_scene_reports
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND street = "Humphrey Street";
/*
Knowledge gained:
reportID is 295
theft done at 10:15am
3 witnesses
all reports mentions bakery
*/


-- Finds interviews mentioning "bakery"
SELECT
  *
FROM
  interviews
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND transcript LIKE "%bakery%";
/*
Knowledge gained:
within 10 mins of theft, thief drove away from parking lot
Thief withdrew money from ATM on leggett Street earlier same morning
Thief called someone for less than a minute while leaving the bakery
Thief planning to take earliest flight out of Fiftyville tomorrow
Person on the other end to purchase ticket
*/


-- Finds names of all who made a withdrawal the given day and location
SELECT
  name
FROM
  people
  JOIN bank_accounts ON people.id = bank_accounts.person_id
  JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND atm_location = "Leggett Street"
  AND transaction_type = "withdraw";


-- Finds the names of all who owns a car that exited the parkinglot between 10:15 and 10:25
SELECT
  people.name
FROM
  people
  JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND HOUR = 10
  AND MINUTE > 15
  AND MINUTE < 25
  AND activity = "exit";


-- Finds the names of those who made a phonecall less that 60 seconds long on the given day
SELECT
  name
FROM
  phone_calls
  JOIN people ON phone_calls.caller = people.phone_number
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND duration < 60


-- Finds the names of those on a flight out of Fiftyville the day after
SELECT
  people.name
FROM
  people
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN flights ON passengers.flight_id = flights.id
  JOIN airports ON flights.origin_airport_id = airports.id
WHERE
  city LIKE "fiftyville"
  AND year = 2021
  AND month = 7
  AND day = 29;


/* Finds the names of those who:
- have a car that existed the parkinglot between 10:15 and 10:25
- made made a withdrawal the given day and location
- made a phonecall less than 60 seconds on the given day
- Are on a flight out of Fiftyville the day after
*/
SELECT
  name
FROM
  people
  JOIN bank_accounts ON people.id = bank_accounts.person_id
  JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND atm_location = "Leggett Street"
  AND transaction_type = "withdraw"

INTERSECT

SELECT
  people.name
FROM
  people
  JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND HOUR = 10
  AND MINUTE > 15
  AND MINUTE < 25
  AND activity = "exit"

INTERSECT

SELECT
  people.name
FROM
  phone_calls
  JOIN people ON phone_calls.caller = people.phone_number
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND duration < 60

INTERSECT

SELECT
  people.name
FROM
  people
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN flights ON passengers.flight_id = flights.id
  JOIN airports ON flights.origin_airport_id = airports.id
WHERE
  city LIKE "fiftyville"
  AND year = 2021
  AND month = 7
  AND day = 29;

/*
+-------+
| name  |
+-------+
| Bruce |
| Diana |
+-------+
*/

-- ==================================================


SELECT
  people.name, hour, minute
FROM
  people
  JOIN passengers ON people.passport_number = passengers.passport_number
  JOIN flights ON passengers.flight_id = flights.id
  JOIN airports ON flights.origin_airport_id = airports.id
WHERE
  city LIKE "fiftyville"
  AND year = 2021
  AND month = 7
  AND day = 29
ORDER BY
  hour, minute
LIMIT
  1;
