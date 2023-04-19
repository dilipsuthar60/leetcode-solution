/**
 * @param {number} millis
 */
async function sleep(millis) {
    let promise=new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve();
        },millis);
    });
    return promise;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */