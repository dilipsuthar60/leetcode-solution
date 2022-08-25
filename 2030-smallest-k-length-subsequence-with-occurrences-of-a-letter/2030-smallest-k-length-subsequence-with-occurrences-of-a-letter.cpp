 class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int rep) 
    {
        int n=s.size();
        int restletter=count(s.begin(),s.end(),letter);
        string stack="";
        for(int i=0;i<n;i++)
        {
            while(stack.size()&&stack.back()>s[i]&&(n+stack.size()-i)>k&&(stack.back()!=letter||rep<restletter))
            {
                if(stack.back()==letter)
                {
                    rep++;
                }
                stack.pop_back();
            }
            if(stack.size()<k&&(s[i]==letter||stack.size()+rep<k))
            {
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