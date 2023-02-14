class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i=a.size()-1;
        int j=b.size()-1;
        string ans="";
        int carry=0;
        while(i>=0||j>=0)
        {
            int first=i>=0?(a[i--]-'0'):0;
            int second=j>=0?(b[j--]-'0'):0;
            int sum=(first+second+carry);
            ans.push_back(char(sum%2+'0'));
            carry=sum/2;
        }
        if(carry)
        {
            ans.push_back(char(carry+'0'));
        }
        while(ans.size()>1&&ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};