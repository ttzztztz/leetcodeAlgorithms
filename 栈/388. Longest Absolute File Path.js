/**
 * @param {string} input
 * @return {number}
 */
var lengthLongestPath = function(input) {
  let answer = 0;
  let cur = [];
  
  const splited = input.split('\n')
  
  splited.forEach(item => {
      let _tCnt = 0;
      
      const len = item.length;
      for (let i = 0; i < len; i++) {
          if (item[i] == '\t') _tCnt++;
          else break;
      }
      
      while (cur.length > _tCnt) {
          cur.pop();
      }
      
      cur.push(item.substr(_tCnt));
      
      const isFile = item.includes('.')
      if (isFile) {
          answer = Math.max(answer, cur.join('/').length);
      }
  });
  
  return answer;
};