class Solution {
public:
    string minInteger(string num, int k) {
        const int N = num.size();
        
        string answer;
        vector<vector<int>> digit(10, vector<int>{});
        vector<int> order(10, 0);
        init();
        
        for (int i = 0; i < N; i++) {
            const int d = num[i] - '0';
            digit[d].push_back(i + 1);
        }
        
        for (int i = 0; i < N; i++) {
            const int d = num[i] - '0';
            for (int a = 0; a <= 9; a++) {
                if (order[a] >= digit[a].size()) continue;
                
                const int pos = digit[a][order[a]];
                const int cost = pos - query(pos) - 1;
                if (cost <= k) {
                    k -= cost;
                    inc(pos, 1);
                    order[a]++;
                    answer += '0' + a;
                    break;
                }
            }
        }
        
        return answer;
    }
private:
    int f[30005];
    void init() {
        memset(f, 0, sizeof f);
    }
    int lowbit(int x) {
        return x & (-x);
    }
    int query(int x) {
        int answer = 0;
        while (x) {
            answer += f[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void inc(int x, int y) {
        while (x && x <= 30000) {
            f[x] += y;
            x += lowbit(x);
        }
    }
};
