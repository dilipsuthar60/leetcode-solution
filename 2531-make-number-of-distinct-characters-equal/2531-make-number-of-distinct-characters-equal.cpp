class Solution {
public:
    bool isItPossible(string a, string b) 
    {
        vector<int>d1(26,0),d2(26,0);
        int count1=0;
        int count2=0;
        for(auto it:a)
        {
            d1[it-'a']++;
            if(d1[it-'a']==1)
            {
                count1++;
            }
        }
        for(auto it:b)
        {
            d2[it-'a']++;
            if(d2[it-'a']==1)
            {
                count2++;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(d1[i]>0)
            {
                d1[i]--;
                if(d1[i]==0)
                {
                    count1--;
                }
                for(int j=0;j<26;j++)
                {
                    if(d2[j])
                    {
                        d2[j]--;
                        if(d2[j]==0)
                        {
                            count2--;
                        }
                        d2[i]++;
                        if(d2[i]==1)
                        {
                            count2++;
                        }
                        d1[j]++;
                        if(d1[j]==1)
                        {
                            count1++;
                        }
                        if(count1==count2)
                        {
                            return true;
                        }
                        d2[j]++;
                        if(d2[j]==1)
                        {
                            count2++;
                        }
                        d2[i]--;
                        if(d2[i]==0)
                        {
                            count2--;
                        }
                        d1[j]--;
                        if(d1[j]==0)
                        {
                            count1--;
                        }
                    }
                }
                d1[i]++;
                if(d1[i]==1)
                {
                    count1++;
                }
            }
        }
        return false;
    }
};