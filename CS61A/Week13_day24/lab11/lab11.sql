.read sp20data.sql

CREATE TABLE obedience AS
--  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";
    SELECT seven, instructor FROM students;

CREATE TABLE smallest_int AS
--  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";
    SELECT time, smallest FROM students WHERE smallest > 2 ORDER BY smallest LIMIT 20;

CREATE TABLE matchmaker AS
--  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";
    select s1.pet, s1.song, s1.color, s2.color
	from students as s1, students as s2
	where s1.pet = s2.pet and s1.song = s2.song and s1.time < s2.time;

-- Ways to stack 4 dogs to a height of at least 170, ordered by total height
CREATE TABLE stacks_helper(dogs, stack_height, last_height);

-- Add your INSERT INTOs here


CREATE TABLE stacks AS
  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";
