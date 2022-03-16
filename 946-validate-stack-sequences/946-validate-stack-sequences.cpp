class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int n=pushed.size();
        int i=0;
        int j=0;
        for(auto &it:pushed)
        {
            pushed[i++]=it;
            while(i&&pushed[i-1]==popped[j])
            {
                i--;
                j++;
            }
        }
        return i==0;
    }
};