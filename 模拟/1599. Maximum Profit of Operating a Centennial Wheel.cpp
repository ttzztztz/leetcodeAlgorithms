class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = 99999999, ans_t = 0;
        
        int wait = 0, cnt = 0, ttl = 0, i = 0;
        for (; i < customers.size(); i++) {
            wait += customers[i];
            
            cnt++;
            const int person = min(4, wait);
            wait -= person;
            ttl += person;
            const int prof = ttl * boardingCost - cnt * runningCost;
            if (prof > 0 && prof > ans_t) {
                ans_t = prof;
                ans = i + 1;
            }
        }
        
        while (wait > 0) {
            cnt++;
            const int person = min(4, wait);
            wait -= person;
            ttl += person;
            const int prof = ttl * boardingCost - cnt * runningCost;
            if (prof > 0 && prof > ans_t) {
                ans_t = prof;
                ans = i + 1;
            }
            i++;
        }
        
        if (ans == 99999999) return -1;
        else return ans;
    }
};
