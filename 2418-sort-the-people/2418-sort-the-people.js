/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function(names, heights) {
    let nums=[];
    for(let i=0;i<names.length;i++){
        nums.push([heights[i],names[i]]);
    }
    nums.sort((a,b)=>b[0]-a[0]);
    let ans=[]
    for(let it of nums){
        ans.push(it[1]);
    }
    return ans;
};