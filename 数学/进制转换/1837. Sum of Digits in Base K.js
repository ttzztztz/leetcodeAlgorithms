/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
 var sumBase = function(n, k) {
    const str = n.toString(k);
    let ans = 0;
    [...str].forEach(item => {
       ans += item.charCodeAt(0) - '0'.charCodeAt(0);
    });
    return ans;
};