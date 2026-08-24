# Write your MySQL query statement below
(select u.name as results from Users u join (select user_id,count(*) as c from MovieRating group by user_id) as m on u.user_id=m.user_id order by m.c desc,u.name limit 1)

UNION ALL

(select m.title as results from movies m join (select movie_id,avg(rating)as average from MovieRating WHERE EXTRACT(YEAR_MONTH FROM created_at) = 202002  group by movie_id) as r on m.movie_id=r.movie_id order by r.average desc,m.title limit 1)

