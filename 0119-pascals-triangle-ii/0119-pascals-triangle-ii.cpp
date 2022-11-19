class Solution {
public:
    vector<int> getRow(int n) {
           vector<int>prev;
        prev.push_back(1);
        for(int i=1;i<=n;i++)
        {
            vector<int>curr;
            curr.push_back(1);
            if(i==1)
            {
                curr.push_back(1);
            }
            else
            {
                for(int i=1;i<prev.size();i++)
                {
                    curr.push_back(prev[i-1]+prev[i]);
                }
                curr.push_back(1);
            }
            prev=curr;
        }
        return prev;
    }
};