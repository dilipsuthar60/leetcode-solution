class Solution:
    def reachableNodes(self, n: int, edges: List[List[int]], res: List[int]) -> int:
        dp = defaultdict(set)
        for a,b in edges:
            dp[a].add(b)
            dp[b].add(a)
        vis=set(res)    
        vis.add(0)
        q=deque([0])
        count=0
        while q:
            temp=q.popleft()
            for it in dp[temp]:
                if it not in vis:
                    # count+=1
                    q.append(it)
                    vis.add(it)
        return len(vis)-len(res)
        