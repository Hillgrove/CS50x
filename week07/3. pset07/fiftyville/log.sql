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
SELECT DISTINCT account_number, amount FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
/*
Knowledge gained:
    list of account numbers and amount withdrawn
*/

