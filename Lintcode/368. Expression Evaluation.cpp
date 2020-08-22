/**
 * @param expression: a list of strings
 * @return: an integer
 */
const evaluateExpression = function (expression) {
    try {
        const ans = eval(expression.join(''));
        if (ans === undefined) return 0;
        else return ans;
    } catch (e) {
        return 0;
    }
}


