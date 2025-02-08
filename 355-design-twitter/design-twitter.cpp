class Twitter {
public:
    unordered_map<int,unordered_set<int>> follows,followers;
    unordered_map<int,deque<pair<int,int>>> feed;
    int t = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        feed[userId].push_front({t++,tweetId});
        if(feed[userId].size()>10)
        feed[userId].pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        auto dq = feed[userId];
        while(!dq.empty())
        {
            pq.push(dq.front());
            dq.pop_front();
        }
        auto s = follows[userId];
        for(auto user:s)
        {
            auto dqi = feed[user];
            while(!dqi.empty())
            {
                pq.push(dqi.front());
                dqi.pop_front();
            }
        }
        vector<int> v;
        int c = 0;
        while(c<10 && !pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
            c++;
        }
        return v;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId)
        return ;
        follows[followerId].insert(followeeId);
        followers[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
        followers[followeeId].erase(followerId);
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