class Solution {
public:
    bool find(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) 
    {
        int n=s.size();
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return find(s,l+1,r)||find(s,l,r-1);
            }
            l++;
            r--;
        }
        return true;
       
    }
};
/*
bool validPalindrome(string s) {
	int left = 0, right = s.length() - 1;
	while (left < right) {
		if (s[left] != s[right]) {
			return isPalin(s, left + 1, right) || isPalin(s, left, right - 1);
		}
		left++;
		right--;
	}
	return true;
}

bool isPalin(string s, int left, int right) {
	while (left < right) {
		if (s[left] != s[right]) return false;
		left++;
		right--;
	}
	return true;
}
*/