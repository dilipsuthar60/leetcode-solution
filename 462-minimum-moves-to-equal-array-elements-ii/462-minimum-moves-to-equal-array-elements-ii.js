/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums){
    nums.sort((a,b)=>a-b);
    let n=nums.length;
    let mid=Math.floor(n/2);
    let step=0;
    for(let i=0;i<n;i++){
        step+=Math.abs(nums[mid]-nums[i]);
    }
    return step;
};