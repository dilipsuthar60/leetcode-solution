/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) 
{
    let nums=[];
    let curr=[];
    for(let it of arr){
        if(curr.length<size){
            curr.push(it);
        }
        if(curr.length==size){
            nums.push(curr);
            curr=[];
        }
        
    }
    if(curr.length){
        nums.push(curr);
    }
    return nums;
};
