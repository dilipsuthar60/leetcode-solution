class Solution {
public:
    int minPartitions(string n) 
    {
        int max_digit=*max_element(n.begin(),n.end());
        return max_digit-'0';
    }
};