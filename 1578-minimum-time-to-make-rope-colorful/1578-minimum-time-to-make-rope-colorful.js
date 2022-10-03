/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(s,nums) 
{
    let cost=0;
    let n=s.length;
    for(let i=1;i<n;i++){
        if(s[i]==s[i-1]){
            cost+=Math.min(nums[i],nums[i-1]);
            nums[i]=Math.max(nums[i],nums[i-1]);
        }
    }
    return cost;
};