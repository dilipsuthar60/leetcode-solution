/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    nums.sort((a,b)=>a-b);
    let len=1;
    let count=1;
    let n=nums.length;
    if(n==0) return 0;
    for(let i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
        if(nums[i-1]+1==nums[i]){
            count++;
        }
        else{
            len=Math.max(len,count);
            count=1;
        }
        }
    }
    return Math.max(count,len);
};