SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists where name = 'Post Malone');
