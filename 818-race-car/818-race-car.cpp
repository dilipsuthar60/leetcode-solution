class Solution {
public:
    int racecar(int target) 
    {
        queue<pair<int,int>>q;
        q.push({0,1});
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto [pos,speed]=q.front();
                q.pop();
                if(pos==target)
                {
                    return level;
                }
                if(abs(pos)>2*target)
                {
                    continue;
                }
                q.push({pos+speed,speed*2});
                if((pos+speed>target&&speed>0)||(pos+speed<target&&speed<0))
                {
                    q.push({pos,speed>0?-1:1});
                }
            }
            level++;
        }
        return -1;
    }
};