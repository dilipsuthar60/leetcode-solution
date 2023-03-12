class Solution {
public:
    bool find(char ch)
    {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int vowelStrings(vector<string>& word, int left, int right) 
    {
        int count=0;
        for(int i=left;i<=right;i++)
        {
            if(find(word[i][0])&&find(word[i].back()))
            {
                count++;
            }
        }
        return count;
    }
};