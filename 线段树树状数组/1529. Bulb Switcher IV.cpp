class Solution {
public:
    int minFlips(string target) {
        memset(data, 0, sizeof data);
        const int N = target.size();
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            const int stat = i + 1;
            
            const int f = query(stat);
            const bool change = f % 2 == 1;
            if ((target[i] == '1' && change) || (target[i] == '0' && !change)) {
                continue;
            } else {
                answer++;
                inc(stat, 1);
            }
            
        }
        return answer;
    }
private:
    int data[100005];
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int u) {
        int answer = 0;
        while (u) {
            answer += data[u];
            u -= lowbit(u);
        }
        return answer;
    }
    void inc(int u, int v) {
        while (u && u <= 100000) {
            data[u] += v;
            u += lowbit(u);
        }
    }
};
