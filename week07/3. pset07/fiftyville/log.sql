-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Clues adress and time
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street LIKE "Humphrey Street";
/*
Knowledge gained:
    reportID is 295
    theft done at 10:15am
    3 witnesses
    all reports mentions bakery
 */

SELECT * from interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";
/*
Knowledge gained:
    within 10 mis of theft, thief drove away from parking lot
    Thief 
*/