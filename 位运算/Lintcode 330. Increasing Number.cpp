class Solution {
public:
    /**
     * @param N:  a positive integer N
     * @return: return a maximum integer less than N, each digit of which must be monotonically increasing.
     */
    long long getIncreasingNumber(long long N) {
        const vector<int> s = {1,2,3,4,5,6,7,8,9};
        long long answer = 0;
        for (int i = 1; i < (1 << 9); i++) {
            string x;
            for (int j = 0; j < 9; j++) {
                if (i & (1 << j)) x.push_back('0' + s[j]);
            }
            
            long long v = stoll(x);
            if (v < N) answer = max(answer, v);
        }
        return answer;
    }
};
