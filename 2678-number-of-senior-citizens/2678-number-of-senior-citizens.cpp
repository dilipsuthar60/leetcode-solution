class Solution {
public:
    int countSeniors(vector<string>&nums)
    {
        int count=0;
        for(auto it:nums)
        {
            int value=stoi(it.substr(11,2));
            if(value>60)
            {
                count++;
            }
        }
        return count;
    }
};