/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function(dominoes) {
    let last = '';
    while (last !== dominoes) {
        last = dominoes;
        dominoes = dominoes.replace(/R\.L/g, 'T');
        dominoes = dominoes.replace(/\.L/g, 'LL');
        dominoes = dominoes.replace(/R\./g, 'RR');
        dominoes = dominoes.replace(/T/g, 'R.L');
    }
    return dominoes;
};
