class Solution {
public:
    int minMovesToMakePalindrome(string s) 
    {
        int n=s.size();
        int step=0;
        int left=0;
        int right=n-1;
        while(left<right)
        {
            int l=left;
            int r=right;
            while(s[l]!=s[r])
            {
                r--;
            }
            if(l==r)
            {
                swap(s[l],s[l+1]);
                step++;
            }
            else
            {
            for(int i=r;i<right;i++)
            {
                swap(s[i],s[i+1]);
                step++;
            }
            left++;
            right--;
            }
        }
        return step;
    }
};