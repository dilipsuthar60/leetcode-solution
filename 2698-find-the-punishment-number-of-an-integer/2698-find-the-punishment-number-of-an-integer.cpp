class Solution {
public:
    bool find(string &s,int index,int target)
    {
        if(index>=s.size())
        {
            return target==0;
        }
        for(int i=index;i<s.size();i++)
        {
            int value=stoi(s.substr(index,i-index+1));
            if(find(s,i+1,target-value))
            {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int cost=0;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i*i);
            if(find(s,0,i))
            {
                cost+=i*i;
            }
        }
        return cost;
    }
};