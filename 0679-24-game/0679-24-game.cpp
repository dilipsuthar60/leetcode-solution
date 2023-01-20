class Solution {
public:
    vector<double>comb(double a,double b)
    {
        return {a+b,a-b,a*b,a/b};
    }
    bool find(vector<double>nums)
    {
        if(nums.size()==1)
        {
            return abs(nums[0]-24)<1e-5;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i==j)
                {
                    continue;
                }
                vector<double>t;
                for(int k=0;k<nums.size();k++)
                {
                    if(i!=k&&j!=k)
                    {
                        t.push_back(nums[k]);
                    }
                }
                vector<double>c=comb(nums[i],nums[j]);
                for(auto it:c)
                {
                    t.push_back(it);
                    if(find(t))
                    {
                        return true;
                    }
                    t.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) 
    {
        vector<double>nums(cards.begin(),cards.end());
        return find(nums);
    }
};