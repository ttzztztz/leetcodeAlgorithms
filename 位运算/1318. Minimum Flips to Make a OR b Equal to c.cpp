class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        for (int i = 0; i < 32; i++) {
            const int mask = 1 << i;
            
            const int _a = a & mask, _b = b & mask, _c = c & mask;
            if (_c) { // 1
                if (!_a && !_b) {
                    answer++;
                }
            } else { // 0
                if (_a) answer++;
                if (_b) answer++;
            }
        }
        return answer;
    }
};
