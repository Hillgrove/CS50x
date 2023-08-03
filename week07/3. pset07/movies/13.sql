-- Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.

SELECT name
FROM people
JOIN stars s1 ON people.id = s1.person_id
JOIN movies m1 ON s1.movie_id = m1.id
JOIN stars s2 ON people.id = s2.person_id
JOIN movies m2 ON s2.person_id = m2.id
WHERE people.name LIKE "Kevin Bacon" AND people.year = 1958