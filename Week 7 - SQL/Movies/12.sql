-- 12) List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred
SELECT title FROM movies AS m JOIN stars AS s ON m.id = s.movie_id JOIN people AS p on s.person_id = p.id
WHERE p.name = "Johnny Depp"
AND title IN
(
    SELECT title
    FROM movies AS m
    JOIN stars AS s ON m.id = s.movie_id
    JOIN people as P on s.person_id = p.id
    WHERE p.name = "Helena Bonham Carter"
);