/**
 * @param {Function} fn
 */
function memoize(fn) {
    let memo={};
    return function(...args) 
    {
        let key=args.join('$%#$');
        if(key in memo){
            return memo[key];
        }
        return memo[key]=fn(...args);
    }
}