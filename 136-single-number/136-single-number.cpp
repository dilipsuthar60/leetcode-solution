class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int Xor=0;
        for(auto it:nums)
        {
            Xor=Xor^it;
        }
        return Xor;
    }
};