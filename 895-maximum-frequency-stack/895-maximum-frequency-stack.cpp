class FreqStack
{
public:
    int max_freq=0;
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>st;
    FreqStack() 
    { 
    }
    void push(int val)
    { 
        max_freq=max(max_freq,++freq[val]);
        st[freq[val]].push(val);
    }
    int pop()
    { 
        int val=st[max_freq].top();
        st[max_freq].pop();
        int x=freq[val];
        freq[val]--;
        if(st[x].size()==0)
        {
            max_freq--;
        }
        return val;
    }
};
