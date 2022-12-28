class MovieRentingSystem
{
    public:
    vector<set<pair<int,int>>>av=vector<set<pair<int,int>>>(10010);
    vector<set<pair<int,int>>>pr=vector<set<pair<int,int>>>(10010);
    set<pair<int,pair<int,int>>>st;
    MovieRentingSystem(int n, vector<vector < int>> &entries) 
    {
        for(auto it:entries)
        {
            av[it[1]].insert({it[2],it[0]});
            pr[it[1]].insert({it[0],it[2]});
        }
    }
    vector<int> search(int movie) 
    {
        int index=0;
        vector<int>ans;
        for(auto it:av[movie])
        {
            ans.push_back(it.second);
            index++;
            if(index>=5)
            {
                break;
            }
        }
        return ans;
    }

    void rent(int shop, int movie) 
    {
        auto it=pr[movie].lower_bound({shop,-1e9});
        int price=(*it).second;
        av[movie].erase({price,shop});
        st.insert({price,{shop,movie}});
    }

    void drop(int shop, int movie)
    {
        auto it=pr[movie].lower_bound({shop,-1e9});
        int price=(*it).second;
        av[movie].insert({price,shop});
        st.erase({price,{shop,movie}});
    }

    vector<vector < int>> report() 
    {
        int index=0;
        vector<vector<int>>v;
        for(auto it:st)
        {
            v.push_back({it.second.first,it.second.second});
            index++;
            if(index>=5)
            {
                break;
            }
        }
        return v;
    }
};