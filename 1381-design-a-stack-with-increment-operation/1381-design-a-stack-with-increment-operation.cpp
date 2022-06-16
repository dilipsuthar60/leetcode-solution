class CustomStack {
public:
    vector<int>stack,inc;
    int limit;
    CustomStack(int maxSize) 
    {
        limit=maxSize;
    }
    
    void push(int x) 
    {
        if(stack.size()<limit)
        {
            stack.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() 
    {
        if(stack.size()==0)
        {
            return -1;
        }
        int index=stack.size()-1;
        if(index)
        {
            inc[index-1]+=inc[index];
        }
        int ans=stack.back()+inc[index];
        stack.pop_back();
        inc.pop_back();
        return ans;
    }
    
    void increment(int k, int val) 
    {
        int i=min(k,(int)stack.size())-1;
        if(i>=0)
        inc[i]+=val;
    }
};
