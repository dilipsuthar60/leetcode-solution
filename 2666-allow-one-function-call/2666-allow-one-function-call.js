/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let yes=true;
    return function(...args){
        // console.log(...args);
        if(yes){
            let value=fn(...args);
            yes=false;
            return value;
        }
        if(yes===false){
            return undefined;
        }
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
