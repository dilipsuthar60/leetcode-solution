class Solution {
public:
     int find(vector<string>&word,int index,vector<int>&freq,vector<int>&score)
    {
        if(index==(int)word.size())
        {
            return 0;
        }
        int not_take=find(word,index+1,freq,score);
        int take=0;
        bool flag=true;
        int count=0;
        for(auto it:word[index])
        {
            if(freq[it-'a']==0)
            {
                flag=false;
            }
            freq[it-'a']--;
            count+=score[it-'a'];
        }
        if(flag)
        {
            take=count+find(word,index+1,freq,score);
        }
        for(auto it:word[index])
        {
            freq[it-'a']++;
        }
        return max(not_take,take);
    }
    int maxScoreWords(vector<string>&words,vector<char>&lett, vector<int>&score)
    {
        vector<int>freq(26,0);
        for(auto it:lett)
        {
            freq[it-'a']++;
        }
        return find(words,0,freq,score);
    }
};