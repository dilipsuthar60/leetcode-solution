 class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) 
    {
        int n=s.size();
        int restletter=count(s.begin(),s.end(),letter);
        string stack="";
        int size=0;
        for(int i=0;i<n;i++)
        {
            while(size>0&&stack.back()>s[i]&&(n+size-i)>k&&(stack.back()!=letter||rep<restletter))
            {
                if(stack.back()==letter)
                {
                    rep++;
                }
                stack.pop_back();
                size--;
            }
            if(size<k&&(s[i]==letter||size+rep<k))
            {
                size++;
                stack.push_back(s[i]);
                if(s[i]==letter)
                {
                    rep--;
                }
            }
            if(s[i]==letter)
            {
                restletter--;
            }
        }
        return stack;
    }
};