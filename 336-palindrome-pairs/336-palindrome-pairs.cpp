// class Solution {

// private:
// 	bool isPalindrome(string& word, int l, int r) {
// 		while (l < r)
// 		{
// 			if (word[l] != word[r]) return false;
// 			l++; r--;
// 		}
// 		return true;
// 	}
// public:
// 	vector<vector<int>> palindromePairs(vector<string>& words) {
// 		unordered_map<string, int> mp;
// 		vector<vector<int>> ans;
// 		int emptyInd = -1;
// 		vector<int> indexOfPalindromes;
// 		for (int i = 0; i < words.size(); ++i)
// 		{
// 			if (words[i] == "")
// 			{
// 				emptyInd = i;
// 				continue;
// 			}
// 			if (isPalindrome(words[i], 0, words[i].size() - 1))
// 				indexOfPalindromes.push_back(i);
// 			string str = words[i];
// 			//Inserting reverse so that we dont have to reverse every substring in later part
// 			reverse(begin(str), end(str));
// 			mp[str] = i;
// 		}
// 		for (int i = 0; i < words.size(); ++i)
// 		{
// 			for (int cut = 0; cut < words[i].size(); ++cut)
// 			{
// 				//Current String gives Left + Mid
// 				//We need to check whether Mid is Palindrome or not
// 				//If yes, we need to search for Right
// 				// Left = {0, cut-1}
// 				// Mid = {cut, words[i].size() - 1}
// 				if (isPalindrome(words[i], cut, words[i].size() - 1))
// 				{
// 					string right = words[i].substr(0, cut);
// 					if (mp.find(right) != end(mp) && mp[right] != i)
// 					{
// 						ans.push_back(vector<int> {i, mp[right]});
// 					}
// 				}
// 				//Current String gives Mid + Right
// 				//We need to check whether Mid is Palindrome or not
// 				//If yes, we need to search for Left
// 				// Mid = {0, cut-1}
// 				// Right = {cut, words[i].size() - 1}
// 				if (isPalindrome(words[i], 0, cut - 1))
// 				{
// 					string left = words[i].substr(cut);
// 					if (mp.find(left) != end(mp) && mp[left] != i)
// 					{
// 						ans.push_back(vector<int> {mp[left], i});
// 					}
// 				}
// 			}
// 		}
// 		if (emptyInd != -1)
// 			for (int x : indexOfPalindromes)
// 			{
// 				ans.push_back(vector<int> {emptyInd, x});
// 				ans.push_back(vector<int> {x, emptyInd});
// 			}
// 		return ans;
class Solution {
public:
    bool is_pal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>&nums) 
    {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>pal_index;
        int empty=-1;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]=="")
            {
                empty=i;
                continue;
            }
            if(is_pal(nums[i],0,nums[i].size()-1))
            {
                pal_index.push_back(i);
            }
            string str=nums[i];
            reverse(str.begin(),str.end());
            mp[str]=i;
        }
        int size=0;
        for(int i=0;i<n;i++)
        {
            size=nums[i].size();
            for(int cut=0;cut<size;cut++)
            {
                if(is_pal(nums[i],cut,size-1))
                {
                    string right=nums[i].substr(0,cut);
                    if(mp.find(right)!=mp.end()&&mp[right]!=i)
                    {
                        ans.push_back({i,mp[right]});
                    }
                }
            }
            
            for(int cut=0;cut<size;cut++)
            {
                if(is_pal(nums[i],0,cut-1))
                {
                    string right=nums[i].substr(cut);
                    if(mp.find(right)!=mp.end()&&mp[right]!=i)
                    {
                        ans.push_back({mp[right],i});
                    }
                }
            }
        }
        if(empty!=-1)
        {
            for(auto it:pal_index)
            {
                ans.push_back({empty,it});
                ans.push_back({it,empty});
            }
        }
        return ans;
    }
};