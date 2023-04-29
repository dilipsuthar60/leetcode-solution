class Solution {
public:
    int find(vector<int>&nums1,vector<int>&nums2,int index)
    {
        unordered_set<int>s;
        for(int i=0;i<=index;i++)
        {
            s.insert(nums1[i]);
        }
        int count=0;
        for(int i=0;i<=index;i++)
        {
            if(s.find(nums2[i])!=s.end())
            {
                count++;
            }
        }
        return count;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        for(int i=0,n=A.size();i<n;i++)
        {
            int count=find(A,B,i);
            ans.push_back(count);
        }
        return ans;
    }
};