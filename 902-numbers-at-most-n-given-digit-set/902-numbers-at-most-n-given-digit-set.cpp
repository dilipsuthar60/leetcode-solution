  	class Solution {
   	public:
   	    vector < int>nums;
   	    string s;
        int dp[10][2][2];
   	    int find(int n,int pos=0,int tight=1,int first=0)
   	    {
   	        if(pos==n)
   	        {
   	            return 1;
   	        }
            if(dp[pos][tight][first]!=-1)
            {
                return dp[pos][tight][first];
            }
   	        int ans=0;
   	        if(first==0)
   	        {
   	            ans+=find(n,pos+1,0,first);
   	        }
   	        if(tight==1)
   	        {
   	            for(int i=0;i < nums.size()&&nums[i]<=s[pos]-'0';i++)
   	            {
   	                int new_tight=0;
   	                if(nums[i]==s[pos]-'0')
   	                {
   	                    new_tight=1;
   	                }
   	                ans+=find(n,pos+1,new_tight,1);
   	            }
   	        }
   	        else
   	        {
   	            for(auto it:nums)
   	            {
   	                ans+=find(n,pos+1,0,1);
   	            }
   	        }
   	        return dp[pos][tight][first]=ans;
   	    }
   	    int atMostNGivenDigitSet(vector<string>& digits, int n) 
   	    {
            memset(dp,-1,sizeof(dp));
   	        s=to_string(n);
   	        for(auto it:digits)
   	        {
   	            nums.push_back(stoi(it));
   	        }
   	        return find(s.size())-1;
   	    }
   	};