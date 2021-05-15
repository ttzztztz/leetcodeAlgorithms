/**
 * @param {string} s
 * @return {boolean}
 */
 var isNumber = function(s) {
    return !Number.isNaN(Number(s)) && !s.includes('Infinity');
};
