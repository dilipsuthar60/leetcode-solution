class FrequencyTracker {
public:
    unordered_map<int,int>mp;
    multiset<int>s;
    FrequencyTracker() {
        mp.clear();
        s.clear();
    }
    
    void add(int val)
    {
        int prev=mp[val];
        if(s.find(prev)!=s.end())
        {
           s.erase(s.find(prev));
        }
        mp[val]++;
        s.insert(mp[val]);
    }
    
    void deleteOne(int number) {
        if(mp.find(number)!=mp.end())
        {
            s.erase(s.find(mp[number]));
            mp[number]--;
            s.insert(mp[number]);
            if(mp[number]==0)
            {
                mp.erase(number);
            }
            
        }
    }
    
    bool hasFrequency(int f) 
    {
        if(s.find(f)!=s.end()&&*s.find(f)>0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */