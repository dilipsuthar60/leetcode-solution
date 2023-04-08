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








// if(node == NULL) // if node is null, then simply return null
//         {
//             return NULL;
//         }
        
//         Node* first = new Node(node -> val, {}); // make a copy of first node
//         mp[node] = first;
        
//         queue<Node*> q; //For bfs, we create queue
//         q.push(node); // push into queue
        
//         while(q.empty() == false) // until q. empty == false
//         {
//             Node* curr = q.front(); // extract front node
//             q.pop(); // pop that from queue
            
//             for(auto adj: curr -> neighbors) // now travel in adjcant
//             {
//                 if(mp.find(adj) == mp.end()) // if not present in map
//                 {
//                     mp[adj] = new Node(adj -> val, {}); // then create copy
//                     q.push(adj); // push nto the queue
                    
//                 }
                
//                 mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
//             }
//         }
        
//         return mp[node];















