class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int count=0;
        auto find=[&](vector<int>&v)
        {
            multiset<int>s;
            for(int i=0;i<v.size();i++)
            {
                auto it=s.upper_bound(v[i]);
                if(it!=s.end())
                {
                    s.erase(it);
                }
                s.insert(v[i]);
            }
            return v.size()-s.size();
        };
        for(int i=0;i<k;i++)
        {
            vector<int>v;
            for(int j=i;j<arr.size();j+=k)
            {
                v.push_back(arr[j]);
            }
            count+=find(v);
        }
        return count;
    }
};