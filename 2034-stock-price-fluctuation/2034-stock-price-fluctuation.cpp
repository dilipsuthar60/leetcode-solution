class StockPrice {
public:
    map<int,int>mp;
    multiset<int>s;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price){
        if(mp.find(timestamp)==mp.end())
        {
            mp[timestamp]=price;
            s.insert(price);
        }
        else
        {
            int prev_val=mp[timestamp];
            mp[timestamp]=price;
            s.erase(s.find(prev_val));
            s.insert(price);
        }
    }
    
    int current() {
        return (*mp.rbegin()).second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};