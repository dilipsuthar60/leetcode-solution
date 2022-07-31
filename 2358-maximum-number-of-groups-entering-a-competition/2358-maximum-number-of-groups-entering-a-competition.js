/**
 * @param {number[]} grades
 * @return {number}
 */
var maximumGroups = function(grades) {
    let len=grades.length;
    let l=0;
    let r=1e9;
    let ans=-1;
    while(l<=r){
        let mid=(l+r)>>1;
        if(mid*(mid+1)/2<=len){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
};