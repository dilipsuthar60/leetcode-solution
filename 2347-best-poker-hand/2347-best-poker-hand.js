/**
 * @param {number[]} ranks
 * @param {character[]} suits
 * @return {string}
 */
var bestHand = function(rank, st) 
{
    let list={};
    for(let it of st){
        if(!list[it]){
            list[it]=1;
        }
        else{
            list[it]+=1;
        }
    }
    if(Object.keys(list).length===1) return "Flush";
    let map={};
    let istwo=0;
    for(let it of rank){
        if(!map[it]){
            map[it]=1;
        }
        else{
            map[it]+=1;
        }
        if(map[it]===3){
            return "Three of a Kind";
        }
        if(map[it]===2){
            istwo=1;
        }
    }
    if(istwo===1) return "Pair";
    return "High Card";
};