-- Write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Bradley Cooper.
-- You may assume that there is only one person in the database with the name Jennifer Lawrence.

SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people p1 ON stars.person_id = people.id
JOIN people p2 ON stars.person_id = people.id
WHERE p1.name LIKE "Bradley Cooper" AND p2.name LIKE "Jennifer Lawrence";