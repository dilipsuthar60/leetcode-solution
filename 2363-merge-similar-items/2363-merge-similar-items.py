class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        mp={}
        for val,wt in items1:
            if val in mp:
                mp[val]+=wt
            else:
                mp[val]=wt
                
        for val,wt in items2:
            if val in mp:
                mp[val]+=wt
            else:
                mp[val]=wt
        ans=[]
        for a,b in mp.items():
            ans.append([a,b])
        ans.sort()    
        return ans    
                
        