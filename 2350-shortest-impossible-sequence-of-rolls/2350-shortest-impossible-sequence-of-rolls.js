/**
 * @param {number[]} rolls
 * @param {number} k
 * @return {number}
 */
var shortestSequence = function(nums, k) {
    let ans=0;
    let st=new Set();
    for(let it of nums){
        st.add(it);
        if(st.size===k){
            ans++;
            st=new Set();
        }
    }
    return ans+1;
};