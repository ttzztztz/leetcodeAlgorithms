/**
 * @param {string} sentence1
 * @param {string} sentence2
 * @return {boolean}
 */
var areSentencesSimilar = function(sentence1, sentence2) {
    const arr1 = sentence1.split(' '), arr2 = sentence2.split(' ');
    
    const ok = (a1, a2) => {
        let i = 0, j = 0;
        while (i < Math.min(a1.length, a2.length)) {
            if (a1[i] === a2[i]) {
                i++;
            } else {
                break;
            }
        }
        
        while (Math.min(a1.length - j - 1, a2.length - j - 1) >= 0) {
            if (a1[a1.length - j - 1] === a2[a2.length - j - 1]) {
                j++;
            } else {
                break;
            }
        }
        
        // console.log(i, j);
        return i + j >= a1.length
    };
    
    if (arr1.length < arr2.length) return ok(arr1, arr2);
    else return ok(arr2, arr1);
};
