class Solution {
public:
    /**
     * @param n: An integer.
     * @return: Return [minF(n), maxF(n)].
     */
    vector<int> minMax(int n) {
        vector<int> answer(2);
        
        const int tmp[] = {0, 1, 1, 0};
        answer[0] = tmp[n % 4];
        answer[1] = n - tmp[(n - 1) % 4];
        
        return answer;
    }
};
