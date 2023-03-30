class Solution {
public:
    bool find(int n)
    {
        if(n==1)
        {
            return false;
        }
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) 
    {
        vector<int>prime;
        for(int i=1;i<=1100;i++)
        {
            if(find(i))
            {
                prime.push_back(i);
            }
        }
        int n=nums.size();
        int prev=nums.back();
//           int flg = 0;
//         int prev = nums[n-1];
//         for(int i=n-2; i>=0; i--){
//             if(nums[i]<prev){prev = nums[i]; continue;}
//             flg = 1;
//             for(int sub=0; sub<prime.size() && prime[sub]<nums[i]; sub++){
//                 if(nums[i]-prime[sub]<prev){
//                     prev = nums[i]-prime[sub];
//                     flg = 0;
//                     break;
//                 }
//             }
//             if(flg) break;

//         }
//         return !flg;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<prev)
            {
                prev=nums[i];
            }
            else
            {
                int f=0;
                for(int j=0;j<prime.size()&&prime[j]<nums[i];j++)
                {
                    if(nums[i]-prime[j]<prev)
                    {
                        nums[i]-=prime[j];
                        prev=nums[i];
                        f=1;
                        break;
                    }
                }
                if(!f)
                {
                    return false;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                return false;
            }
        }
        return true;
    }
};