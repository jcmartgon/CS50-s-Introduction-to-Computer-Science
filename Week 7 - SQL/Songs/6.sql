-- Lists the names of songs that are by Post Malone:
SELECT name FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name LIKE "Post Malone");