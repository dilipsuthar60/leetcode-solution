/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */
var arrayStringsAreEqual = function(word1, word2) {
    let s1="";
    for(let it of word1){
        s1+=it;
    }
    let s2="";
    for(let it of word2){
        s2+=it;
    }
    return s1===s2;
};