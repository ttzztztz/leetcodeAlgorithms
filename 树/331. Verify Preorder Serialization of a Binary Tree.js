/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    const tree = preorder.split(',');
    let idx = 0;

    const dfs = () => {
        if (idx >= tree.length) {
            return false;
        }

        if (tree[idx] === '#') {
            idx++;
            return true;
        } else {
            idx++;
            return dfs() && dfs();
        }
    };

    return dfs() && idx === tree.length;
};
