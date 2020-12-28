class Solution {
public:
    bool confusingNumber(int N) {
        const vector<int> kNext = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int ans = 0;
        const int before = N;
        while (N) {
            const int t = N % 10;
            if (kNext[t] == -1) return false;
            ans = ans * 10 + kNext[t];
            N /= 10;
        }
        
        return (ans != before);
    }
};
