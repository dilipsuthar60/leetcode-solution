class SummaryRanges {
public:
    set<int>s;
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int val) 
    {
       s.insert(val);
    }
    
    vector<vector<int>> getIntervals() 
    {
        if(s.size()==0)
        {
            return {};
        }
        vector<vector<int>>ans;
        auto it=s.begin();
        vector<int>v{*it,*it};
        it++;
        while(it!=s.end())
        {
            if(v[1]+1==*it)
            {
                v[1]=v[1]+1;
            }
            else
            {
                ans.push_back(v);
                v={*it,*it};
            }
            it++;
        }
        ans.push_back(v);
        return ans;
    }
};
