class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n=pref.size();
        for(int i=n-1;i>0;i--)
        {
            // cout<<(pref[i]^nums[i-1])<<" ";
            pref[i]^=pref[i-1];
            // curr=curr^pref[i];
        }
        return pref;
    }
};