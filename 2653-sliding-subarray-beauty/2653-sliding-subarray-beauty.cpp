
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        multi_ordered_set <int> s;
        for(int i=0;i<k;i++)
        {
            s.insert(nums[i]);
        }
        vector<int>v;
                    v.push_back(*s.find_by_order(x-1)>0?0:*s.find_by_order(x-1));

        for(int i=k,n=nums.size();i<n;i++)
        {
            s.erase(s.find_by_order(s.order_of_key(nums[i-k])));
            s.insert(nums[i]);
            v.push_back(*s.find_by_order(x-1)>0?0:*s.find_by_order(x-1));
        }
        return v;
    }
};