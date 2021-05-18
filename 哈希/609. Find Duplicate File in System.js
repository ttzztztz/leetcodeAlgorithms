/**
 * @param {string[]} paths
 * @return {string[][]}
 */
 var findDuplicate = function(paths) {
    const ans = [];
    const hmap = {};
    
    for (const data of paths) {
        const splitted = data.split(' ');
        const basePath = splitted[0];
        
        for (let s = 1; s < splitted.length; s++) {
            let value = '';
            
            let i = splitted[s].length - 1;
            for (let balance = 0; i >= 0; i--) {
                if (splitted[s][i] === '(') {
                    balance--;

                    if (balance === 0) {
                        break;
                    }

                } else if (splitted[s][i] == ')') {
                    balance++;
                }

                if(i !== splitted[s].length - 1) value = splitted[s][i] + value;
            }

            const filename = splitted[s].substr(0, i);
            if (hmap[value] === undefined) {
                hmap[value] = [];
            }
            hmap[value].push(basePath + '/' + filename);
        }
    }
    
    Object.entries(hmap).forEach(([k, v]) => {
        if (v.length > 1) ans.push(v);
    });
    return ans;
};