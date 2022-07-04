
var candy = function(nums) {
    const n=nums.length;
    let left=new Array(n);
    let right=new Array(n);
    left.fill(1);
    right.fill(1);   
    for(let i=1;i<n;i++){
        if(nums[i-1]<nums[i]){
            left[i]=left[i-1]+1;
        }
    }
    for(let i=n-2;i>=0;i--){
        if(nums[i]>nums[i+1]){
            right[i]=right[i+1]+1;
        }
    }
    let ans=0;
    for(let i=0;i<n;i++){
        ans+=Math.max(left[i],right[i]);
    }
    return ans;
};