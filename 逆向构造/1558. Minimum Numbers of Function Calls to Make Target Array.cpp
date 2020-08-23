class Solution {
public:
    int minOperations(vector<int>& A) {
        int odd = 0, mx = 0;
        for (int i : A) {
            int cnt = 0;
            while (i > 0) {
                if (i % 2 == 1) odd++;
                cnt++;
                i /= 2;
            }
            mx = max(mx, cnt - 1);
        }
        return odd + mx;
    }
};
