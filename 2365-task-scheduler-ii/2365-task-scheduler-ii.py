class Solution:
    def taskSchedulerII(self, tasks: List[int], space: int) -> int:
        mp={}
        day=0
        for i in tasks:
            if i in mp:
                day=max(day,mp[i]+space+1)
            mp[i]=day
            day+=1
        return day    
        