/**
let answer = [];
    
    // traverse the array
    for(let i=0; i<arr.length; i++){
        
        // check if element is instance of array and depth is not equal to 0
        if(n>0 && Array.isArray(arr[i])){
            
            // recursively call the function for this array and push the flattened array to the answer array
            answer.push(...flat(arr[i], n-1));
        }
        // else directy push the current array
        else{
            answer.push(arr[i]);
        }
    }
    
    return answer;
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) 
{
    if(n==0){
        return arr;
    }
    let answer=[];
    console.log(answer);
    for(let i=0;i<arr.length;i++){
        if(n>0&&Array.isArray(arr[i])){
            answer.push(...flat(arr[i],n-1));
        }
        else{
            answer.push(arr[i]);
        }
    }
    return answer;
};