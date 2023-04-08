/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        unordered_map<Node*,Node*>mp;
        Node* first=new Node(node->val,{});
        mp[node]=first;
        queue<Node*>q;
        q.push(node);
        while(q.size())
        {
            auto curr=q.front();
            q.pop();
            for(auto temp:curr->neighbors)
            {
                if(mp.find(temp)==mp.end())
                {
                    mp[temp]=new Node(temp->val,{});
                    q.push(temp);
                }
                mp[curr]->neighbors.push_back(mp[temp]);
            }
        }
        return first;
    }
};








