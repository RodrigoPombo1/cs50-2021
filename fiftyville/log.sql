-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;
SELECT 
SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;