class Solution {
public:
     int integerReplacement(int n)
    {
         queue<long long >q;
         q.push(n);
         int level=0;
         while(!q.empty())
         {
             int size=q.size();
             for(int i=0;i<size;i++)
             {
                 auto temp=q.front();
                 q.pop();
                 if(temp==1)
                 {
                     return level;
                 }
                 if((temp&1))
                 {
                     q.push(temp-1);
                     q.push(temp+1);
                 }
                 else
                 {
                     q.push(temp/2);
                 }
             }
             level++;
         }
         return 0;
    }
};