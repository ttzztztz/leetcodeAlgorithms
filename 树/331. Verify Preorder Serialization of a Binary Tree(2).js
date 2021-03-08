/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    let slot = 1;
    const splitted = preorder.split(',');
    for (const item of splitted) {
        slot--;

        if (slot < 0) {
            return false;
        }
        if (item !== '#') {
            slot += 2;
        }
    }
    return slot === 0;
};
