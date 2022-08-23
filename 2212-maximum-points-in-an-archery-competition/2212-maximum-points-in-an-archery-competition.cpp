class Solution {
public:
    vector<int>ans;
    int max_score=0;
    void find(int index,int usearrow,int score,vector<int>&alice,vector<int>&temp)
    {
        if(index==12)
        {
            if(max_score<score)
            {
                max_score=score;
                ans=temp;
                if(usearrow)
                {
                    ans.back()+=usearrow;
                }
            }
            return ;
        }
        int need=alice[index]+1;
        if(usearrow>=need)
        {
            temp[index]=need;
            find(index+1,usearrow-need,score+index,alice,temp);
            temp[index]=0;
        }
        find(index+1,usearrow,score,alice,temp);
    }
    vector<int> maximumBobPoints(int num, vector<int>& alice) 
    {    
        vector<int>temp(12);
        find(0,num,0,alice,temp);
        return ans;
    }
};