/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    let n=pushed.length;
    let i=0;
    let j=0;
    for(let it of pushed){
        pushed[i++]=it;
        while(i>0&&pushed[i-1]==popped[j]){
                i--;
                j++;
            }
    }
    return i==0;
};