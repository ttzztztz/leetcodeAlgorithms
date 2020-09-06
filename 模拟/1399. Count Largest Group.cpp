class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> cnt;
        for (int i = 1; i <= n; i++) {
            int number = i, sum = 0;
            while (number) {
                const int d = number % 10;
                sum += d;
                number /= 10;
            }
            
            cnt[sum]++;
        }
        
        int currentSize = 0, answer = 0;
        for (auto& p : cnt) {
            if (p.second > currentSize) {
                currentSize = p.second;
                answer = 1;
            } else if (p.second == currentSize) {
                answer ++;
            }
        }
        return answer;
    }
};
