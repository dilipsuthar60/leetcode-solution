class Solution {
public:
    bool find(vector<vector<char>>&v,int i,int j,string &s,int index)
    {
        if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]!=s[index])
        {
            return false;
        }
        if(index==s.size()-1)
        {
            return true;
        }
        char ch=v[i][j];
        v[i][j]='*';
        bool x=find(v,i-1,j,s,index+1)||find(v,i+1,j,s,index+1)||find(v,i,j-1,s,index+1)||find(v,i,j+1,s,index+1);
        v[i][j]=ch;
        return x;
        
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(find(board,i,j,word,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};