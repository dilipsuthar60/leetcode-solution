class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        mp={}
        for i in nums:
            s=str(i)
            s=s[::-1]
            val=int(s)
            if i-val in mp:
                mp[i-val]+=1
            else:
                mp[i-val]=1
        ans=0
        for a,b in mp.items():
            ans+=(b*(b-1)//2)
        return ans%(10**9+7)   
            
        
        