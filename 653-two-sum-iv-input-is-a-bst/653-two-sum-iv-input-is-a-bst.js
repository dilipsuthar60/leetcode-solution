
let nums;
function find(root){
    if(!root) return ;
    find(root.left);
    nums.push(root.val);
    find(root.right);
}
var findTarget = function(root, k) {
    nums=[];
    find(root);

    let l=0;
    let r=nums.length-1;
    while(l<r){
        let sum=nums[l]+nums[r];
        if(sum==k){
            return true;
        }
        if(sum<k){
            l++;
        }
        else{
            r--;
        }
    }
    return false;
};