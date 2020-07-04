class Solution {
public:
    /**
     * @param s0: the number s[0]
     * @param n: the number n
     * @param k: the number k
     * @param b: the number b
     * @param m: the number m
     * @param a: area
     * @return: the way can paint the ceiling
     */
    long long painttheCeiling(int s0, int n, int k, int b, int m, long long a) {
        // write your code here
        vector<long long> all = {s0};
        long long prev = s0;
        for (int i = 0; i < n - 1; i++) {
            long long nxt = k * prev + b;
            nxt %= m;
            nxt += prev + 1;
            
            all.push_back(nxt);
            prev = nxt;
        }
        
        long long answer = 0;
        for (int r = n - 1, l = 0; l <= r; ) {
            if (all[l] > a / all[r]) {
                r--;
            } else {
                answer += (r - l) * 2 + 1;
                l++;
            }
        }
        return answer;
    }
};
