class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;
        for (int i = left; i <= right; i++) {
            bool ok = true;
            
            int num = i;
            while (num) {
                const int d = num % 10;
                num /= 10;
                if (d == 0 || i % d != 0) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) answer.push_back(i);
        }
        return answer;
    }
};
