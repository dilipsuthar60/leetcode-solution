class ATM {
public:
    vector<int>coin={20,50,100,200,500};
    long long  b[5]={0};
    ATM() 
    {
    }
    
    void deposit(vector<int> nums) 
    {
        for(int i=0;i<5;i++)
        {
            b[i]+=nums[i];
        }
    }
    
    vector<int> withdraw(int amount) 
    {
        vector<int>need(5,0);
        for(int i=4;i>=0;i--)
        {
            need[i]=min(b[i],0ll+amount/coin[i]);
            amount-=need[i]*coin[i];
        }
        if(amount)
        {
            return {-1};
        }
        for(int i=0;i<5;i++)
        {
            b[i]-=need[i];
        }
        return need;
    }
};