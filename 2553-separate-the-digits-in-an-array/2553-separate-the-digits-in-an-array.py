class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans=[]
        for i in nums:
            for ch in str(i):
                ans.append(int(ch))
        return ans        
        