-- Keep a log of any SQL queries you execute as you solve the mystery.
--intro
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

--check interviews
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

--first interview clue
SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;
--second interview clue
SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street";
--third interview clue
SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
SELECT passport_number FROM passengers WHERE flight_id IN 

--get the name of all the people who have done these actions
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28);
SELECT name FROM people WHERE people.id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street"));
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;)

--match them to see if there is someone who has done all of them (it should be our thief)
SELECT name FROM people
WHERE name IN (SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28)
AND name IN (SELECT name FROM people WHERE people.id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street"))))
AND name IN (SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60));