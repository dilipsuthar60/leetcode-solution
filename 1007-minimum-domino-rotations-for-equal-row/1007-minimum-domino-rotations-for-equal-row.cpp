class Solution {
public:
    int find(vector<int>&t,vector<int>&b,int val)
    {
        int n=t.size();
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++)
        {
            if(count1!=INT_MAX)
            {
                if(val==t[i])
                {
                }
                else if(val==b[i])
                {
                    count1++;
                }
                else
                {
                    count1=INT_MAX;
                }
            }
            if(count2!=INT_MAX)
            {
                if(val==b[i])
                {
                }
                else if(val==t[i])
                {
                    count2++;
                }
                else
                {
                    count2=INT_MAX;
                }
            }
        }
        return min(count1,count2);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int ans1=find(tops,bottoms,tops[0]);
        int ans2=find(tops,bottoms,bottoms[0]);
        if(ans1==INT_MAX&&ans2==INT_MAX)
        {
            return -1;
        }
        return min(ans1,ans2);
    }
};