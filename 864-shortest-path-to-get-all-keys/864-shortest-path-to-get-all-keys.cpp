class Solution {
public:
    class node
    {
        public:
        int x;
        int y;
        int mask;
        node(int x,int y,int mask)
        {
            this->x=x;
            this->y=y;
            this->mask=mask;
        }
    };
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPathAllKeys(vector<string>&mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int k=0;
        int startx,starty;
        startx=starty=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='@')
                {
                    startx=i;
                    starty=j;
                }
                if(mat[i][j]>='A'&&mat[i][j]<='F')
                {
                    k++;
                }
            }
        }
        queue<node>q;
        q.push(node(startx,starty,0));
        int vis[n+1][m+1][70];
        memset(vis,0,sizeof(vis));
        vis[startx][starty][0]=1;
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int j=0;j<size;j++)
            {
                node temp=q.front();
                q.pop();
                // cout<<temp.x<<"  "<<temp.y<<"  "<<temp.mask<<endl;
                if(temp.mask==((1<<k)-1))
                {
                    return level;
                }
                for(auto it:dir)
                {
                    int nx=temp.x+it.first;
                    int ny=temp.y+it.second;
                    int now_mask=temp.mask;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]!='#')
                    {
                        if(isupper(mat[nx][ny]))
                        {
                            if(!(temp.mask&(1<<(mat[nx][ny]-'A'))))
                            {
                                continue;
                            }
                        }
                         if(islower(mat[nx][ny]))
                        {
                            now_mask=(temp.mask|(1<<(mat[nx][ny]-'a')));
                        }
                        if(!vis[nx][ny][now_mask])
                        {
                          q.push({nx,ny,now_mask});
                          vis[nx][ny][now_mask]=1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};