/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var complexNumberMultiply = function(num1, num2) {
    const [a, b] = num1.substr(0, num1.length - 1).split('+').map(i => +i);
    const [c, d] = num2.substr(0, num2.length - 1).split('+').map(i => +i);
    
    return `${a * c - b * d}+${b * c + d * a}i`
};
