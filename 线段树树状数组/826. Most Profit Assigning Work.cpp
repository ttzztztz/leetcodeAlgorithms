class Solution {
public:
    int bit[600005];
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int key, int value) {
        while (key <= 600000) {
            bit[key] = max(bit[key], value);
            key += lowbit(key);
        }
    }
    int query(int key) {
        int answer = 0;
        while (key) {
            answer = max(answer, bit[key]);
            key -= lowbit(key);
        }
        return answer;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        memset(bit, 0, sizeof(bit));
        int answer = 0;
        const int N = difficulty.size(), M = worker.size();

        for (int i = 0; i < N; i++) {
            add(difficulty[i], profit[i]);
        }
        for (int i = 0; i < M; i++) {
            answer += query(worker[i]);
        }

        return answer;
    }
};