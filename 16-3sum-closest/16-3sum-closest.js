/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    nums.sort((a,b)=>a-b);
    let n=nums.length;
    let result=10000000;
    let diff=100000000;
    for(let i=0;i<n-2;i++){
        let l=i+1;
        let r=n-1;
        while(l<r){
            let sum=nums[i]+nums[l]+nums[r];
            if(Math.abs(sum-target)<Math.abs(result-target)){
                result=sum;
            }
            if(sum<target){
                l++;
            }
            else{
                r--;
            }
        }
    }
    return result;
};