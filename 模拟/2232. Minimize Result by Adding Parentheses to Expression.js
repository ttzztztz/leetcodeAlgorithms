/**
 * @param {string} expression
 * @return {string}
 */
var minimizeResult = function(expression) {
    const [l, r] = expression.split('+');
    
    let ans = '', ansVal = Infinity;
    for (let i = 0; i < l.length; i++) {
        const l0 = l.substr(0, i), l1 = l.substr(i);
        for (let j = 1; j <= r.length; j++) {
            const r0 = r.substr(0, j), r1 = r.substr(j);
            
            const curStr = `${l0}(${l1}+${r0})${r1}`;
            const l0e = l0.length > 0 ? l0 : '1';
            const r1e = r1.length > 0 ? r1 : '1';
            const curExpr = l0e + `*(` + l1 + `+` + r0 + `)*` + r1e;
            const curVal = eval(curExpr);
            if (curVal < ansVal) {
                ans = curStr;
                ansVal = curVal;
            }
        }
    }
    return ans;
};
