-- Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.

-- SELECT name
-- FROM people
-- JOIN stars ON people.id = stars.person_id
-- WHERE stars.movie_id = (
--     SELECT movies.id
--     FROM movies
--     JOIN stars ON movies.id = stars.movie_id
--     JOIN people ON stars.person_id = people.id
--     WHERE people.name LIKE "Kevin Bacon" AND people.birth = 1958
-- )

-- SELECT movies.id
-- FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON stars.person_id = people.id
-- WHERE people.name LIKE "Kevin Bacon" AND people.birth = 1958

SELECT name
FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id = (
    SELECT movies.id
    FROM movies
    JOIN stars ON movies.id = stars.movie_id
    JOIN people ON stars.person_id = people.id
    WHERE people.name LIKE "Kevin Bacon" AND people.birth = 1958)