/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    let nums=[];
    return function curried(...args) {
        nums=[...nums,...args];
        if(nums.length==fn.length){
            let result=fn(...nums);
            return result;
        }
        else{
            return curried;
        }
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
