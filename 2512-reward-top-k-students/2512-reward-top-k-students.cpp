class Solution {
public:
    vector<int> topStudents(vector<string>& positive, vector<string>& negative, vector<string>& report, vector<int>& student, int k) 
    {
        unordered_map<string ,int>pos,neg;
        for(auto it:positive)
        {
            pos[it]=0;
        }
        for(auto it:negative)
        {
            neg[it]=0;
        }
        unordered_map<int,int>point;
        for(auto it:student)
        {
            point[it]=0;
        }
        int index=0;
        for(auto it:report)
        {
            it+=' ';
            string s;
            for(int i=0;i<it.size();i++)
            {
                if(it[i]==' ')
                {
                    if(pos.find(s)!=pos.end())
                    {
                        point[student[index]]+=3;
                    }
                    else if(neg.find(s)!=neg.end())
                    {
                        point[student[index]]-=1;
                    }
                    s.clear();
                }
                else
                {
                    s.push_back(it[i]);
                }
            }
            index++;
        }
        vector<pair<int,int>>v(point.begin(),point.end());
        sort(v.begin(),v.end(),[&](auto &a,auto &b){return a.second==b.second?a.first<b.first:a.second>b.second;});
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};



