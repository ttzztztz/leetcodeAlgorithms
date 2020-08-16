class Solution {
public:
    int minOperations(int n) {
        int ttl = 0;
        for (int i = 0; i < n; i++) ttl += 1 + (2 * i);
        const int avg = ttl / n;
        
        int answer = 0;
        for (int i = 0; i < n; i++) answer += abs((2 * i) + 1 - avg);
        return answer / 2;
    }
};
