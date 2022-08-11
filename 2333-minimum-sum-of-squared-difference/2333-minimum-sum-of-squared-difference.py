class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        n=len(nums1)
        target=k1+k2
        nums=[]
        for i in range(0,n):
            nums.append(abs(nums1[i]-nums2[i]))
        nums.sort(reverse=True)
        l=0
        r=10**9
        ans=-1
        while l<=r:
            mid=(l+r)//2
            count=0
            for i in nums:
                count+=max(0,i-mid)
            if count<=target:
                r=mid-1
                ans=mid
            else:
                l=mid+1
        for i in range(0,n):
            target-=max(0,nums[i]-ans)
            nums[i]=min(nums[i],ans)
        for i in range(0,n):
            if target>0 and nums[i]>0:
                nums[i]-=1
                target-=1
        result=0
        for i in nums:
            result+=(i*i)
        return result
            
        
        