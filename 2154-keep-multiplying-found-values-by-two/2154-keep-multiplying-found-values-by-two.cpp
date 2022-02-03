class Solution {
public:
    int findFinalValue(vector<int>& nums, int num) 
    {
        set<int>s(nums.begin(),nums.end());
        if(s.count(num))
        {
            num=2*num;
        }
        while(s.find(num)!=s.end())
        {
            num=2*num;
        }
        return num;
    }
};