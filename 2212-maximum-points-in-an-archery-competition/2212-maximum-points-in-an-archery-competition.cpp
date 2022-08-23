class Solution {
public:
    // int find(int mask,vector<int>&nums,int &arrow,vector<int>&temp)
    // {
    //     int score=0;
    //     for(int i=0;i<12;i++)
    //     {
    //         if(mask&(1<<i))
    //         {
    //             int need=nums[i]+1;
    //             if(need>arrow)
    //             {
    //                 return -1;
    //             }
    //             temp[i]=need;
    //             score+=i;
    //             arrow-=need;
    //         }
    //     }
    //     return score;
    // }
    vector<int>ans;
    int max_score=0;
    void find(int index,int arrow,int usearrow,int score,vector<int>&alice,vector<int>temp)
    {
        // cout<<usearrow<<"  "<<score<<endl;
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
            find(index+1,arrow,usearrow-need,score+index,alice,temp);
            temp[index]=0;
        }
        find(index+1,arrow,usearrow,score,alice,temp);
    }
    vector<int> maximumBobPoints(int num, vector<int>& alice) 
    {    
        vector<int>temp(12);
        find(0,num,num,0,alice,temp);
        return ans;
        // vector<int>ans(12,0);
        // vector<int>temp(12,0);
        // int max_score=0;
        // for(int i=0;i<(1<<12);i++)
        // {
        //     int usearrow=num;
        //     int score=find(i,alice,usearrow,temp);
        //     if(score!=-1&&max_score<score)
        //     {
        //         max_score=score;
        //         ans=temp;
        //         if(usearrow)
        //         {
        //             ans[0]+=usearrow;
        //         }
        //     }
        //     temp=vector<int>(12,0);
        // }
        // return ans;
    }
};