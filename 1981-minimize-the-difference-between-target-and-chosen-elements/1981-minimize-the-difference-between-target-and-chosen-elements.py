class Solution:
    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        n=len(mat)
        m=len(mat[0])
        dp=1
        for i in range(0,n):
            temp=0
            for j in range(0,m):
                temp|=(dp<<mat[i][j])
            dp=temp
        ans=10**9
        for i in range(0,5000):
            if dp&(1<<i):
                ans=min(ans,abs(i-target))
        return ans
                    
                
                
                
        
        
        