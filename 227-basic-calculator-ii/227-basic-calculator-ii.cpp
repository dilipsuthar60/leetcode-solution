class Solution {
public:
    string operators="()/+-*";
    vector<string>read(string s)
    {
        int i=0;
        int n=s.size();
        vector<string>list;
        while(i<n)
        {
            if(s[i]==' ')
            {
                i++;
                continue;
            }
            if(operators.find(s[i])!=string::npos)
            {
                list.push_back(string(1,s[i]));
                i++;
            }
            else
            {
                string curr="";
                while(i<n&&s[i]>='0'&&s[i]<='9')
                {
                    curr+=s[i];
                    i++;
                }
                list.push_back(curr);
            }
        }
        return list;
    }
    int priority(string s)
    {
        if(s==string(1,'/')||s==string(1,'*'))
        {
            return 1;
        }
        return 0;
    }
    vector<string>infix_to_posfix(vector<string>&s)
    {
        stack<string>st;
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            if(operators.find(s[i])==string::npos)
            {
                ans.push_back(s[i]);
            }
            else
            {
                while(st.size()&&priority(st.top())>=priority(s[i]))
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    int eval(vector<string>&nums)
    {
        int n=nums.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==string(1,'+'))
            {
                int n2=s.top();
                s.pop();
                int n1=s.top();
                s.pop();
                s.push(n1+n2);
            }
            else if(nums[i]==string(1,'-'))
            {
                int n2=s.top();
                s.pop();
                int n1=s.top();
                s.pop();
                s.push(-n2+n1);
            }
            else if(nums[i]==string(1,'*'))
            {
                int n2=s.top();
                s.pop();
                int n1=s.top();
                s.pop();
                s.push(n1*n2);
            }
            else if(nums[i]==string(1,'/'))
            {
                int n2=s.top();
                s.pop();
                int n1=s.top();
                s.pop();
                s.push(n1/n2);
            }
            else
            {
                s.push(stoi(nums[i]));
            }
        }
        return s.top();
    }
    int calculate(string s) {
        vector<string>nums=read(s);
        nums=infix_to_posfix(nums);
        return eval(nums);
    }
};