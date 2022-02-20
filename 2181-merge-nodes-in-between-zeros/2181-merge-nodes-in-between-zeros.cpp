/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) 
    {
        vector<int>nums;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        vector<int>ans;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(sum)
                ans.push_back(sum);
                sum=0;
            }
            else
            {
                sum+=nums[i];
            }
        }
        n=ans.size();
        ListNode*start=new ListNode(-1);
        ListNode*end=start;
        for(int i=0;i<n;i++)
        {
            end->next=new ListNode(ans[i]);
            end=end->next;
        }
        return start->next;
    }
};