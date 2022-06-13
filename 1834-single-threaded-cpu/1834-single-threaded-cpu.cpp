class Solution {
public:
    class node
    {
        public:
        int end_time;
        int index;
        node(int end_time,int index)
        {
            this->end_time=end_time;
            this->index=index;
        }
    };
    class cmp
    {
        public:
            bool operator()(node&a, node&b)
            {
                if(a.end_time==b.end_time)
                {
                    return a.index>b.index;
                }
                return a.end_time>b.end_time;
            }
    };
    vector<int> getOrder(vector<vector<int>>&nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        priority_queue<node,vector<node>,cmp>pq;
        int i=0;
        long long time=nums[0][0];
        vector<int>ans;
        while(i<n||pq.size())
        {
            while(i<n&&nums[i][0]<=time)
            {
                pq.push(node(nums[i][1],nums[i][2]));
                i++;
            }
            if(pq.size()==0)
            {
                time=nums[i][0];
                pq.push(node(nums[i][1],nums[i][2]));
                i++;
            }
            node current_node=pq.top();
            int burst=current_node.end_time;
            int index=current_node.index;
            pq.pop();
            ans.push_back(index);
            time+=burst;
        }
        return ans;
    }
};