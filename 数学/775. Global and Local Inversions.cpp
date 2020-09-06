class Solution {
public:
    int bit[20005];
    void init() {
        for (int i = 0; i <= 20000; i++) {
            bit[i] = 0;
        }
    }
    int lowbit(int x) {
        return x & (-x);
    }
    int query(int x) {
        int answer = 0;
        while (x) {
            answer += bit[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void increment(int x, int y) {
        while (x && x <= 20000) {
            bit[x] += y;
            x += lowbit(x);
        }
    }
    bool isIdealPermutation(vector<int>& A) {
        int local = 0, global = 0;
        
        const int N = A.size();
        for (int i = 0; i + 1 < N; i++) {
            if (A[i] > A[i + 1]) local++;
        }
        
        init();
        for (int i = N - 1; i >= 0; i--) {
            global += query(A[i] + 1);
            increment(A[i] + 1, 1);
        }
        
        return local == global;
    }
};
