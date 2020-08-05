/**
 * @param {string[]} transactions
 * @return {string[]}
 */
var invalidTransactions = function(transactions) {
  const splited = transactions.map(item => item.split(','));
  const answer = [];
  const N = splited.length;
  
  for (let i = 0; i < N; i++) {
      const [name, time, amount, city] = splited[i];
      if (+amount > 1000) {
          answer.push(transactions[i]);
          continue;
      }
      
      let found = false;
      for (let j = 0; j < N; j++) {
          if (i == j) continue;
          
          const [name2, time2, amount2, city2] = splited[j];
          if (name2 === name && city2 !== city && Math.abs((+time2) - (+time)) <= 60) {
              found = true;
              break;
          }
      }
      if (found) {
          answer.push(transactions[i]);
      }
  }
  
  return answer;
};