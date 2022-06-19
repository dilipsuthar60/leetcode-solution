class MKAverage {
public:
    multiset<int>left,mid,right;
    int k;
    int m;
    long long sum;
    queue<int>q;
    MKAverage(int mt, int kt)
    {
        sum=0;
        m=mt;
        k=kt;
    }
    void remove()
    {
        int val=q.front();
        q.pop();
        if(val<=*left.rbegin())
        {
            left.erase(left.find(val));
            left.insert(*mid.begin());
            sum-=*mid.begin();
            mid.erase(mid.begin());
        }
        else if(val>=*right.begin())
        {
            right.erase(right.find(val));
            right.insert(*mid.rbegin());
            sum-=*mid.rbegin();
            mid.erase(--mid.end());
        }
        else
        {
            sum-=val;
            mid.erase(mid.find(val));
        }
    }
    void add(int val)
    {
        q.push(val);
        if(mid.size()==0)
        {
            if(q.size()==m)
            {
                queue<int>nq=q;
                vector<int>v;
                while(nq.size())
                {
                    v.push_back(nq.front());
                    nq.pop();
                }
                sort(v.begin(),v.end());
                for(int i=0;i<m;i++)
                {
                    if(i<k)
                    {
                        left.insert(v[i]);
                    }
                    else if(i>m-1-k)
                    {
                        right.insert(v[i]);
                    }
                    else
                    {
                        mid.insert(v[i]);
                        sum+=v[i];
                    }
                }
            }
        }
        else if(val<*left.rbegin())
        {
            int curr=*left.rbegin();
            left.insert(val);
            mid.insert(curr);
            left.erase(--left.end());
            sum+=curr;
        }
        else if(val>*right.begin())
        {
            int curr=*right.begin();
            right.erase(right.begin());
            right.insert(val);
            sum+=curr;
            mid.insert(curr);
        }
        else
        {
            sum+=val;
            mid.insert(val);
        }
    }
    void addElement(int num) 
    {
        add(num);
        if(q.size()>m)
        {
            remove();
        }
    }
    
    int calculateMKAverage() 
    {
        if(q.size()<m)
        {
            return -1;
        }
        return sum/(m-k-k);
    } 
};
