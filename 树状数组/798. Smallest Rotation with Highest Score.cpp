class Solution {
public:
    int bestRotation(vector<int> &A) {
        const int MAX = 4e4 + 5, n = A.size();
        memset(data, 0, sizeof data);
        
        int ans = 0, ans_val = 0;
        for (int i = 0; i < n; i++) {
            inc(A[i] - i + MAX, 1);
        }
        ans_val = query(MAX);
        
        for (int i = 1; i < n; i++) {
            inc(A[i - 1] - (i - 1) + MAX, -1);
            inc(A[i - 1] - (n - 1 + i) + MAX, 1);
            
            int cur = query(MAX - i);
            if (cur > ans_val) {
                ans_val = cur;
                ans = i;
            }
        }
        return ans;
    }
private:
    int data[60005];
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int x) {
        int ans = 0;
        while (x) {
            ans += data[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void inc(int x, int y) {
        while (x && x <= 60000) {
            data[x] += y;
            x += lowbit(x);
        }
    }
};
