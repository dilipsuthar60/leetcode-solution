class Solution {
public:
    bool find(vector<vector<int>>&p,vector<vector<int>>&l,long long mid)
    {
        for(int i=0;i<l.size();i++)
        {
            if(mid<l[i][0])
            {
                return false;
            }
            mid=mid-l[i][0]+l[i][1];
        }
        for(int i=0;i<p.size();i++)
        {
            if(mid<p[i][0])
            {
                return false;
            }
            mid=mid-p[i][0]+p[i][1];
        }
        return true;
    }
    long long minimumMoney(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>p,l;
        for(const auto &it:nums)
        {
            if(it[1]>=it[0])
            {
                p.push_back(it);
            }
            else
            {
                l.push_back(it);
            }
        }
        sort(p.begin(),p.end(),[&](auto &a,auto &b){return a[0]>b[0];});
        sort(l.begin(),l.end(),[&](auto &a,auto &b){return (a[1]==b[1])?a[0]>b[0]:a[1]<b[1];});
        long long x=0;
        long long y=1e18;
        long long ans=0;
        while(x<=y)
        {
            long long mid=(x+y)/2;
            if(find(p,l,mid))
            {
                ans=mid;
                y=mid-1;
            }
            else
            {
                x=mid+1;
            }
        }
        return ans;
    }
};
//     static bool cmp2(vector<int> &a,vector<int> &b)
//     {
//        if (a[1]==b[1])
//            return a[0]>b[0];
        
//         return a[1]<b[1];
//     }
    
    
//      static bool cmp1(vector<int> &a,vector<int> &b)
//     {
//         return a[0]>b[0];
//     }
    
//     long long minimumMoney(vector<vector<int>>& transactions) {
        
//         long long low=0,high=0;
//         for (auto x:transactions)
//         {
//           high+=x[0];
//         }
        
//         vector<vector<int>> profit,loss;
        
//         for (auto x:transactions)
//         {
//             if (x[1]>=x[0])
//               profit.push_back({x[0],x[1]});
//             else
//               loss.push_back({x[0],x[1]});  
//         }
        
        
//         sort(profit.begin(),profit.end(),cmp1);
//         sort(loss.begin(),loss.end(),cmp2);
        
        
        
//         long long ans;
        
        
        
//         // for (auto x:transactions)
//         // {
//         //     cout<<x[0]<<" "<<x[1]<<endl;
//         // }
        
//         while (low<=high)
//         {
//             long long mid=high+(low-high)/2;
            
//             if (isPossible(mid,profit,loss))
//             {
//                 ans=mid;
//                 high=mid-1;
//             }
//             else
//             {
//                 low=mid+1;
//             }
            
//         }
        
//         return ans;
        
//     }
    
//     bool isPossible(long long price,vector<vector<int>> &profit,vector<vector<int>> &loss)
//     {
//         for (int i=0;i<loss.size();++i)
//         {
//             if (price<loss[i][0])
//                 return false;
            
//             price-=(loss[i][0]-loss[i][1]);
//         }
        
//         for (int i=0;i<profit.size();++i)
//         {
//             if (price<profit[i][0])
//                 return false;
            
//             price-=(profit[i][0]-profit[i][1]);
//         }
        
//         return true;
//     }