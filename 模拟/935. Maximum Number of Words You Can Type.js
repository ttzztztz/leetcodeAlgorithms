/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
 var canBeTypedWords = function(text, brokenLetters) {
    const hm = {};
    for (const letter of brokenLetters) hm[letter] = true;
    let ans = 0;
    text.split(' ').forEach(word => {
        let ok = true;
        for (const c of word) {
            if (hm[c]) {
                ok = false;
                break;
            }
        }
        
        if (ok) ans++;
    });
    return ans;
};