class Solution {
public:
    int shortestWay(string source, string target) {
        const int n = source.size(), m = target.size();
        int ans = 0, s = 0;
        for (int t = 0; t < m; t++) {
            int add_cnt = 0;
            while (source[s] != target[t]) {
                if (s + 1 >= n) {
                    s = 0;
                    ans++;
                } else {
                    s++;
                }
                
                add_cnt++;
                
                if (add_cnt > n) {
                    return -1;
                }
            }
            if (source[s] == target[t]) {
                if (s + 1 >= n) {
                    s = 0;
                    ans++;
                } else {
                    s++;
                }
            }
        }
        return ans + (s != 0);
    }
};
