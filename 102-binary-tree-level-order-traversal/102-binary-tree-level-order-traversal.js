/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
let ans=[];
function find(root,level){
    if(!root) return ;
    if(level===ans.length){
        ans.push([]);
    }
    ans[level].push(root.val);
    find(root.left,level+1);
    find(root.right,level+1);
}
var levelOrder = function(root) {
    ans=[];
    find(root,0);
    return ans;
};