SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name LIKE "Post Malone");


SELECT songs.name FROM songs JOIN artists ON songs.artist_id = artists.id WHERE artists.name LIKE "Post Malone";