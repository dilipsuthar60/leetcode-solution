class Solution {
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int>v;
        for(int i=0;i<input.size();i++)
        {
            auto curr=input[i];
            if(curr=='-'||curr=='+'||curr=='*')
            {
                vector<int>first=diffWaysToCompute(input.substr(0,i));
                vector<int>second=diffWaysToCompute(input.substr(i+1));
                for(auto it1:first)
                {
                    for(auto it2:second)
                    {
                        if(curr=='+')
                        {
                            v.push_back(it1+it2);
                        }
                        if(curr=='-')
                        {
                            v.push_back(it1-it2);
                        }
                        if(curr=='*')
                        {
                            v.push_back(it1*it2);
                        }
                    }
                }
            }
        }
        if(v.size()==0)
        {
            v.push_back(stoi(input));
            return v;
        }
        return v;
    }
};