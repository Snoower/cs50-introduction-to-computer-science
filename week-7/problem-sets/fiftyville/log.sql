-- Keep a log of any SQL queries you execute as you solve the mystery.
-- To figure out the tables in the db
.schema
-- To see all the crime scene report info
select * from crime_scene_reports;
-- To see all crimes related to theft
select * from crime_scene_reports where description like '%thieft%';
-- To sell all theft crimes that included two people
select * from crime_scene_reports where description like '%theft%' and description like '%two%';
-- Check the bakery security logs
select * from bakery_security_logs
-- Check the phone calls
select * from phone_calls
-- Since both the phone calls and security calls take place during 7/25-7/31, I want to check the crimes committed around that time that include theft
select * from crime_scene_reports where month = 7 and day >= 25 and description like '%theft%';
-- To see what phone calls occurred on the same day
select * from phone_calls where day = 28;
-- To see what activity occurred on the 28th
select * from bakery_security_logs where day = 28;
-- To see interviews that occurred on the day of the incident
select * from interviews where month = 7 and day = 28;
-- According to one interview, the phone call lasted less than a minute, so I want to see what phone calls occurred on that day that lasted less than a minute
select * from phone_calls where day = 28 and duration < 60;
-- Based on the result above, I checked what the names of the callers were
select * from people where phone_number = '(130) 555-0289' or phone_number = '(367) 555-5533' or phone_number = '(286) 555-6063' or phone_number = '(770) 555-1861' or phone_number = '(031) 555-6622' or phone_number = '(826) 555-1652' or phone_number = '(338) 555-6650';
-- According to the same interview, the caller said they are planning on leaving on the next flight out of Fiftyville the next day, the 29th
select * from flights where day = 29 ORDER BY hour;
-- According to that last query, the earliest next day flight was id 36 with origin_airport_id 8, destination_airport_id 4 @ 7/29 at 8:20am, so I want to find out what airport/city the thieves are going to.
select * from airports;
-- Based on the last query, the origin airport is CSF (Fiftyville) and the destination airport is LGA (LaGuardia Airport) in New York City, so now I need to figure out who the thieves are, so I will check the passengers on that flight
select * from passengers where flight_id = 36;
-- Using the info from the last query, I cross-referenced the passport_numbers with the individuals I found when searching for who the caller may be and found 4 individuals who made call that lasted less than a minute and were on the first plane out of Fiftyville the day after the crime: Kenny, Sofia, Taylor, Bruce, so based on a different interviewm, the thief left the bakery parking lot 10 within after the incident, so I will look at the bakery security logs around that time (10:15AM)
select * from bakery_security_logs where day = 28 and hour = 10 and minute < 25 and activity = 'exit';
-- Based on the previous query, the two people who left the bakery parking lot within 10 minutes of the incident were Sofia and Bruce. Based on another interview, the thief went to withdraw money from the atm, so I checked for transactions from both of them
select * from bank_accounts where person_id = 398010 or person_id = 686048;
-- Based on the previous query, the thief is Bruce, so now I need to find the accomplice, so I will see who Bruce called on the day of the incident that lasted less than a minute
select * from phone_calls where caller = '(367) 555-5533' and day = 28 and duration < 60;
-- Based on the previous query, the person he called is (375) 555-8161, so I need to figure out who that is
select * from people where phone_number = '(375) 555-8161';
