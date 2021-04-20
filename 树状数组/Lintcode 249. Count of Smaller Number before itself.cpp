class Solution {
public:
    /**
     * @param A: an integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        init();
        vector<int> all;
        for (int i : A) all.push_back(i);
        sort(all.begin(), all.end());
        auto allend = unique(all.begin(), all.end());
        for (int& i : A) 
            i = lower_bound(all.begin(), allend, i) - all.begin() + 1;
        
        const int N = A.size();
        vector<int> answer(N, 0);
        for (int i = 0; i < N; i++) {
            answer[i] = query(A[i] - 1);
            inc(A[i], 1);
        }
        return answer;
    }
private:
    int val[10005];
    void init() {
        memset(val, 0, sizeof val);
    }
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int u) {
        int answer = 0;
        while (u) {
            answer += val[u];
            u -= lowbit(u);
        }
        return answer;
    }
    void inc(int k, int v) {
        while (k && k <= 10000) {
            val[k] += v;
            k += lowbit(k);
        }
    }
};