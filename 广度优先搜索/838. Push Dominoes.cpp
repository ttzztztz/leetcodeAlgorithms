class Solution {
public:
    string pushDominoes(string dominoes) {
        const int n = dominoes.size();
        
        deque<int> q;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') q.push_back(i);
        }
        
        while (!q.empty()) {
            string t = dominoes;
            const int cnt = q.size();
            
            for (int _ = 0; _ < cnt; _++) {
                const int u = q.front();
                q.pop_front();

                if (dominoes[u] == 'L') { // R.L
                    if (
                        u - 1 >= 0 &&
                        dominoes[u - 1] == '.'
                        && !(u - 2 >= 0 && t[u - 2] == 'R')
                    ) {
                        dominoes[u - 1] = 'L';
                        q.push_back(u - 1);
                    }
                } else if (dominoes[u] == 'R') {
                    if (
                        u + 1 < n &&
                        dominoes[u + 1] == '.'
                        && !(u + 2 < n && t[u + 2] == 'L')
                    ) {
                        dominoes[u + 1] = 'R';
                        q.push_back(u + 1);
                    }
                }
            }
        }
        return dominoes;
    }
};