class Twitter {
public:
    vector<pair<int,int>>tweet;
    unordered_map<int,unordered_map<int,int>>mp;
    Twitter() 
    {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        tweet.push_back({userId,tweetId});
    }
    vector<int> getNewsFeed(int userId) 
    {
        int count=0;
        vector<int>ans;
        for(int i=tweet.size()-1;i>=0&&count<10;i--)
        {
            if(tweet[i].first==userId||mp[userId][tweet[i].first]==1)
            {
                count++;
                ans.push_back(tweet[i].second);
            }
        }
        return ans;
    }
    void follow(int followerId, int followeeId)
    {
        mp[followerId][followeeId]=1;
    }
    void unfollow(int followerId, int followeeId)
    {
        mp[followerId][followeeId]=0;
    }
};