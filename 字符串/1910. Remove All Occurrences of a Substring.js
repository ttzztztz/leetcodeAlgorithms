/**
 * @param {string} s
 * @param {string} part
 * @return {string}
 */
 var removeOccurrences = function(s, part) {
    while (s.includes(part)) {
        s = s.replace(part, "");
    }
    return s;
};