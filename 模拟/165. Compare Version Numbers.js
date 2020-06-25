/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    const v1 = version1.split('.'), v2 = version2.split('.')
    
    for (let i = 0; i < Math.max(v1.length, v2.length); i++) {
        const $1 = +(v1[i] === undefined ? 0 : v1[i]);
        const $2 = +(v2[i] === undefined ? 0 : v2[i]);
        
        if ($1 < $2) return -1;
        else if ($1 > $2) return 1;
    }
    
    return 0
};