-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Clues adress and time
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street LIKE "Humphrey Street";
-- Knowledge gained: reportID is 295, theft done at 10:15am, 3 witnesses, all mentions bakery