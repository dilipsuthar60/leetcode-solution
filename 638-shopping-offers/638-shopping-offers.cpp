class Solution {
public:
    int n;
    vector<int>find(vector<int>&need,vector<int>&of)
    {
        vector<int>now(n,0);
        for(int i=0;i<n;i++)
        {
            now[i]=need[i]-of[i];
        }
        return now;
    }
    bool is_possible(vector<int>&now)
    {
        for(int i=0;i<n;i++)
        {
            if(now[i]<0)
            {
                return false;
            }
        }
        return true;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& sp, vector<int>& need) 
    {
        n=price.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(price[i]*need[i]);
        }
        for(auto it:sp)
        {
            vector<int>now=find(need,it);
            if(is_possible(now))
            {
                ans=min(ans,it.back()+shoppingOffers(price,sp,now));
            }
        }
        return ans;
    }
};