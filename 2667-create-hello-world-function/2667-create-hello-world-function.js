/**
 * @return {Function}
 */
var createHelloWorld = function() {
    let nums="Hello World";
    return function(...args) {
        return nums;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */