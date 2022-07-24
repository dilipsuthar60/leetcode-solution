class FoodRatings {
public:
    unordered_map<string,string>ft;
    unordered_map<string,int>rt;
    unordered_map<string,set<pair<int,string>>>mp;
    FoodRatings(vector<string>& food, vector<string>& cui, vector<int>& rating) 
    {
        for(int i=0;i<cui.size();i++)
        {
            mp[cui[i]].insert({-rating[i],food[i]});
            ft[food[i]]=cui[i];
            rt[food[i]]=rating[i];
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        int prev_r=rt[food];
        string prev_c=ft[food];
        mp[prev_c].erase({-prev_r,food});
        rt[food]=newRating;
        mp[prev_c].insert({-newRating,food});
    }
    
    string highestRated(string cui) 
    {
        auto it=*(mp[cui].begin());
        return it.second;
    }
};