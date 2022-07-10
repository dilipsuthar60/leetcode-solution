class Solution {
public:
    vector<pair<char,int>>find(string s)
    {
        vector<pair<char,int>>v;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]!='_')
            {
                v.push_back({s[i],i});
            }
        }
        return v;
    }
    bool canChange(string start, string target)
    {
        vector<pair<char,int>>nums1=find(start);
        vector<pair<char,int>>nums2=find(target);
        if(nums1.size()!=nums2.size())
        {
            return false;
        }
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            if(nums1[i].first!=nums2[i].first)
            {
                return false;
            }
            if(nums1[i].first=='L')
            {
                if(nums1[i].second<nums2[i].second)
                {
                    return false;
                }
            }
            else 
            {
                if(nums1[i].second>nums2[i].second)
                {
                    return false;
                }
            }
        }
        return true;
    }
};