/**
 * @param {number} num
 * @return {boolean}
 */
var isSameAfterReversals = function(num) {
    const s = (+[...num.toString()].reverse().join('')).toString();
    return num === +[...s].reverse().join('');
};
