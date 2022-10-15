int dp[101][27][101][101];
class Solution {
public:
    string s;
    int solve(int idx, int last, int len, int k ){
        if(k<0)return INT_MAX/2;
        if(idx>=s.size())return 0;
        int &ans=dp[idx][last][len][k];
        if(ans!=-1)return ans;
        if(s[idx]-'a'==last){
            int carry=(len==1||len==9||len==99);
            ans= carry+solve(idx+1, last, len+1, k);
        }
        else {
            ans=min(1+solve(idx+1, s[idx]-'a', 1, k), solve(idx+1, last, len,k-1));
        }
        return ans;
    }
    int getLengthOfOptimalCompression(string str, int k) {
        s=str;
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k);
    }
};

// class Solution {
// public:
//     unordered_map<string,int>mp;
//     int find(string &s,int index,char last,int k,int count=0)
//     {
//         if(k<0)
//         {
//             return 118;
//         }
//         if(index==s.size())
//         {
//             return 0;
//         }
//         string hash=to_string(index)+"@@"+to_string(last)+"@@"+to_string(k)+"##"+to_string(count);
//         if(mp.find(hash)!=mp.end())
//         {
//             return mp[hash];
//         }
//         int ans=115;
//         ans=find(s,index+1,last,k-1,count);
//         if(s[index]!=last)
//         {
//             ans=min(ans,1+find(s,index+1,s[index],k,1));
//         }
//         else
//         {
//             if(count==1||count==9||count==99)
//             {
//                 ans=min(ans,1+find(s,index+1,s[index],k,count+1));
//             }
//             else
//             {
//                 ans=min(ans,find(s,index+1,s[index],k,count+1));
//             }
//         }
//         return mp[hash]=ans;
//     }
//     int getLengthOfOptimalCompression(string s, int k) 
//     {
//         return find(s,0,'z'+1,k);
//     }
// };