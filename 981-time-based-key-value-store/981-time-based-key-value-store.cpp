class TimeMap {
public:
    map<string,map<int,string>>mp;
    TimeMap()
    {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) 
    {
        mp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) 
    {
        if(mp.find(key)==mp.end())
        {
            return "";
        }
        auto &map=mp[key];
         auto it = map.upper_bound(timestamp);
        return it == map.begin() ? "" : prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */