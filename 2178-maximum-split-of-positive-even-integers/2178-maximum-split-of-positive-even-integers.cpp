class Solution {
public:
    bool find(vector<long long>&ans,long long i,long long target)
    {
        if(target==0)
        {
            return true;
        }
        if(target<0||target<i)
        {
            return false;
        }
        ans.push_back(i);
        if(find(ans,i+2,target-i))
        {
            return true;
        }
        ans.pop_back();
        return find(ans,i+2,target);
    }
    vector<long long> maximumEvenSplit(long long num) 
    {
        if(num&1)
        {
            return {};
        }
        vector<long long>ans;
        find(ans,2,num);
        return ans;
    }
};