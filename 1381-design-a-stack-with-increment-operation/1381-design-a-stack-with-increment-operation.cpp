class CustomStack {
public:
    vector<int>stack,inc;
    int limit;
    int count=0;
    CustomStack(int maxSize) 
    {
        limit=maxSize;
    }
    
    void push(int x) 
    {
        if(count<limit)
        {
            count++;
            stack.push_back(x);
            inc.push_back(0);
        }
    }
    
    int pop() 
    {
        if(count==0)
        {
            return -1;
        }
        int index=count-1;
        if(index)
        {
            inc[index-1]+=inc[index];
        }
        int ans=stack.back()+inc[index];
        stack.pop_back();
        inc.pop_back();
        count--;
        return ans;
    }
    
    void increment(int k, int val) 
    {
        int i=min(k,count)-1;
        if(i>=0)
        inc[i]+=val;
    }
};
