class Solution {
public:
    int find(vector<int>&nums)
    {
        int n=nums.size();
        int p=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if((i-1>=0)&&nums[i-1]==10)
            {
                sum+=2*nums[i];
            }
            else if(i-2>=0&&nums[i-2]==10)
            {
                sum+=2*nums[i];
            }
            else
            {
                sum+=nums[i];
            }
        }
        return sum;
    }
    int isWinner(vector<int>& p1, vector<int>& p2) {
        int v1=find(p1);
        int v2=find(p2);
        if(v1>v2)
        {
            return 1;
        }
        if(v2>v1)
        {
            return 2;
        }
        return 0;
    }
};