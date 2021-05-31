use twater;

-- Query 1: Tweet, time, likes, rt, Acc
select user.UNAME as `Account`, `text`,  count(likes.PID) as `likes`,  retweets, `time` from tweet join post on tweet.PID = post.PID join likes on post.PID = likes.PID 
join user on post.UID = user.UID
left outer  join 
(select original_post_id, count(original_post_id) as `retweets` from retweet group by original_post_id) as sub
on post.PID = sub.original_post_id
group by post.PID;




-- Query2 count tweets per acc 
select user.UNAME as `Account`, count(PID) as `# of tweets` 
from user join post 
on user.UID = post.UID
group by user.UID;


-- Query 3: all likes on 1 profile
select user.UNAME as `Account`, count(user.UID) as `# of likes` 
from user join post 
on user.UID = post.UID
join likes
on post.PID = likes.PID
group by user.UID;



-- Query 4: posts in feed for account #2
select post.*  from post left outer join (select followed_id from follow where follower_id = 2) as sub on post.UID = sub.followed_id  where followed_id is not null order by time;


