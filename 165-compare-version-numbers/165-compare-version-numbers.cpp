class Solution {
public:
    int compareVersion(string nums1, string nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        int sum1,sum2;
        sum1=sum2=0;
        while(i<n||j<m)
        {
            while(i<n && nums1[i]!='.')
            {
                sum1=sum1*10+(nums1[i]-'0');
                i++;
            }
            while(j<m&& nums2[j]!='.')
            {
                sum2=sum2*10+(nums2[j]-'0');
                j++;
            }
            if(sum1>sum2)
            {
                return 1;
            }
            if(sum1<sum2)
            {
                return -1;
            }
            sum1=sum2=0;
            i++;
            j++;
        }
        return 0;
    }
};