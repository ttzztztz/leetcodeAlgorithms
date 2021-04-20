class Solution {
public:
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int x) {
        int answer = 0;
        while (x) {
            answer += bit[x];
            x -= lowbit(x);
        }
        return answer;
    }
    void incr(int x, int y) {
        int answer = 0;
        while (x && x <= N) {
            bit[x] += y;
            x += lowbit(x);
        }
    }
    int N;
    vector<int> bit;
    int numTimesAllBlue(vector<int>& light) {
        int answer = 0;
        N = light.size();
        bit = vector<int>(N + 5, 0);
        
        for (int i = 1; i <= N; i++) {
            incr(light[i - 1], 1);
            if (query(i) == i) answer++;
        }
        return answer;
    }
};
