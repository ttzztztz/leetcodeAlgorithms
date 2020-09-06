class Solution {
public:
    bool cmp(const string& s, int len, int $1, int $2) {
        for (int i = 0; i < len; i++) {
            if (s[$1 + i] != s[$2 + i]) return false;
        }
        return true;
    }
    int solve(const string& S, int len) {
        unordered_map<long long, vector<int>> visited;
        const int N = S.size();
        const long long MOD = 1e9+7;
        int left = 0, right = len - 1;
        while (right < N) {
            long long current = prefix[right + 1];
            current -= base[len] * prefix[left];
            current %= MOD;
            current += MOD;
            current %= MOD;
            
            if (visited.count(current) && visited[current].size() >= 1) {
                for (int $2 : visited[current]) {
                    if (cmp(S, len, left, $2)) {
                        return left; 
                    }
                }
            }
            visited[current].push_back(left);
            left++, right++;
        }
        return -1;
    }
    string longestDupSubstring(string S) {
        prefix.push_back(1), base.push_back(1);
        
        const int N = S.size();
        const long long MOD = 1e9+7, seed = 26;
        for (int i = 1; i <= N; i++) {
            base.push_back((base[i - 1] * seed) % MOD);
            prefix.push_back((prefix[i - 1] * seed + S[i - 1] - 'a') % MOD);
        }
        
        int left = 1, right = N - 1;
        int answer_index = -1;
        while (left <= right) {
            const int mid = (left + right) >> 1;
            
            const int tmp = solve(S, mid);
            if (tmp == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
                answer_index = tmp;
            }
        }
        
        if (left - 1 <= 0 || answer_index == -1) return "";
        return S.substr(answer_index, left - 1);
    }
private:
    vector<long long> prefix, base;
};
