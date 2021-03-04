/**
 * @param {string[]} features
 * @param {string[]} responses
 * @return {string[]}
 */
var sortFeatures = function(features, responses) {
    const f = {};
    features.forEach(key => {
        f[key] = 0;
    });
    
    responses.forEach(item => {
        [... new Set(item.split(' '))].forEach(res => {
            if (f[res] !== undefined) {
                f[res]++;
            }
        })
    });
    
    const ans = [];
    Object.entries(f).forEach(([k, v]) => {
        ans.push([k, v]);
    });
    
    ans.sort((lhs, rhs) => rhs[1] - lhs[1]);
    return ans.map(item => item[0]);
};
