/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const paths = path.split('/').filter(item => item.length > 0);
    const stk = [];
    paths.forEach(item => {
        if (item === '.') return;
        else if (item === '..') {
            if (stk.length > 0) stk.pop();
        } else stk.push(item);
    });
    return '/' + stk.join('/');
};
