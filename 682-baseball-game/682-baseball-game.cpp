class Solution {
public:
    int calPoints(vector<string>&nums) 
    {
        vector<int>v;
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(nums[i]=="C")
            {
                if(v.size())
                v.pop_back();
            }
            else if(nums[i]=="D")
            {
                if(v.size())
                v.push_back(v.back()*2);
            }
            else if(nums[i]=="+")
            {
                v.push_back(v.back()+v[v.size()-2]);
            }
            else
            {
                v.push_back(stoi(nums[i]));
            }
        }
        int score=accumulate(v.begin(),v.end(),0);
        return score;
    }
};