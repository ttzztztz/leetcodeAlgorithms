/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    const hash = {}
    const all = cpdomains.map(item => item.split(' '))
    all.forEach((item) => {
        const inc = +(item[0])
        const domains = item[1].split('.')
        for (let i = 0; i < domains.length; i++) {
            const subd = domains.filter((_, idx) => idx >= i).join('.')
            
            if (hash[subd] === undefined) {
                hash[subd] = inc;
            } else {
                hash[subd] = +hash[subd] + +inc;
             }
        }
    })
    
    const answer = Object.entries(hash).map(([k, v]) => `${v} ${k}`)
    return answer
};
