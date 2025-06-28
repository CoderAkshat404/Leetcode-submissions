class Twitter {
public:
    map<int,vector<pair<int,int>>> tweets;
    map<int,set<int>> following;
    int counter;


    Twitter() {
        counter=0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({counter,tweetId});
        following[userId].insert(userId);
        counter++;
       
        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i:following[userId]){
            for(auto j:tweets[i]){
                if(pq.size()==10){
                    pq.push(j);
                    pq.pop();
                }
                else{
                    pq.push(j);
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            
            ans.push_back(pq.top().second);
            pq.pop();

        }
        reverse(ans.begin(), ans.end()); 
        return ans;

    

        
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        
    }

    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        
    }
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */