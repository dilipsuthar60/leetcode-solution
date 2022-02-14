class Solution {
public:
     vector<int>find(unordered_map<int,int>&mp)
    {
        int first_element=0;
        int first_element_f=0;
        int second_element_f=0;
        for(auto it:mp)
        {
            if(it.second>=first_element_f)
            {
                second_element_f=first_element_f;
                first_element=it.first;
                first_element_f=it.second;
            }
            else if(it.second>second_element_f)
            {
                second_element_f=it.second;
            }
        }
        return {first_element,first_element_f,second_element_f};
    }
    int minimumOperations(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int,int>even,odd;
        for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                odd[nums[i]]++;
            }
            else
            {
                even[nums[i]]++;
            }
        }
        vector<int>f1=find(even);
        vector<int>f2=find(odd);
        if(f1[0]!=f2[0])
        {
            return n-f1[1]-f2[1];
        }
        return min(n-f1[1]-f2[2],n-f1[2]-f2[1]);
    }
};