/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function(s, k) {
    const arr = s.split(' ');
    const ans = [];
    
    let cur = 0;
    for (const str of arr) {
        if (cur >= k) {
            break;
        }
        
        ans.push(str);
        cur++;
    }
    
    return ans.join(' ');
};
