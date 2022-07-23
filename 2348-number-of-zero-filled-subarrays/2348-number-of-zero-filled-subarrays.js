/**
 * @param {number[]} nums
 * @return {number}
 */
var zeroFilledSubarray = function(nums) {
    let ans=0;
    let count=0;
    for(let i of nums){
        if(i===0){
            count++;
        }
        else{
            ans+=(count*(count+1)/2);
            count=0;
        }
    }
    ans+=(count*(count+1)/2);
    return ans;
};