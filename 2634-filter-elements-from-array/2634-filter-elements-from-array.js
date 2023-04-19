/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans=[]
    arr.forEach((element,index)=>{
        if(fn(element,index)){
            ans.push(element);
        }
    })
    return ans;
};