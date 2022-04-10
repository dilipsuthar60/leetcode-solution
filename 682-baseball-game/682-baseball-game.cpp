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
                int t=2;
                int sum=0;
                int i=0;
                while(t--)
                {
                    sum+=v[v.size()-i-1];
                    i++;
                }
                v.push_back(sum);
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