class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedSet() 
    {   
        mp.clear();
        v.clear();
    }
    bool insert(int val) 
    {
        bool x=false;
        if(mp.find(val)==mp.end())
        {
            x=true;
            v.push_back(val);
            mp[val]=v.size()-1;
        }
        return x;
    }
    bool remove(int val) 
    {
        bool x=false;
        if(mp.find(val)!=mp.end())
        {
            x=true;
            int value=v.back();
           mp[value]=mp[val];
            v[mp[val]]=value;
            mp.erase(val);
            v.pop_back();
        }
        return x;
    }
    int getRandom()
    {    
        return v[rand()%(v.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */