class Solution {
public:
    int distanceBetweenBusStops(vector<int>& nums, int start, int dest) 
    {
        int n=nums.size();
        int first=0;
        int second=0;
        int i=start;
        while(i!=dest)
        {
            first+=nums[i];
            i=(i+1)%n;
        }
        i=dest;
        while(i!=start)
        {
            second+=nums[i];
            i=(i+1)%n;
        }
        return min(second,first);
    }
};