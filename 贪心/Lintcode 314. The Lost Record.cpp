class Solution {
public:
    /**
     * @param m: An integer
     * @param record: An integer array
     * @return: the smallest total number of the messages, if does not exist, return -1
     */
    int minimumMessages(int m, vector<int> &record) {
        // write your code here
        const int N = record.size();
        vector<int> t = record;
        int answer = 0, sum = 0;
        for (int r = 0; r < N; r++) {
            const int l = r - 2;
            if (r <= 2) {
                if (t[r] != -1) sum += t[r];
            } else {
                if (t[r] != -1) sum += t[r];
                if (t[l - 1] != -1) sum -= t[l - 1];
            }
            
            if (t[r] != -1) answer += t[r];
            if (r >= 2 && sum < m) {
                bool find = false;
                for (int k = r; k >= l; k--) {
                    if (record[k] == -1) {
                        const int inc = m - sum;
                        if (t[k] == -1) t[k] = 0;
                        t[k] += inc;
                        sum += inc;
                        answer += inc;
                        find = true;
                        break;
                    }
                }
                
                if (!find) return -1;
            }
        }
        
        return answer;
    }
};