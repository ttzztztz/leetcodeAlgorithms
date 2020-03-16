class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int answer = 0;
        unordered_set<int> visited;
        const int N = text.size(), MOD = 1e9+7;
        vector<long long> prefix{1}, base{1};
        
        for (int i = 0; i < N; i++) {
            long long cur = prefix[i];
            cur *= 26;
            cur += text[i] - 'a';
            cur %= MOD;
            prefix.push_back(cur);
        }
        
        for (int i = 1; i <= text.size(); i++) {
            long long cur = base[i - 1];
            cur *= 26;
            cur %= MOD;
            base.push_back(cur);
        }
        
        for (int len = 2; len <= N; len += 2) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int i_end = i + (len / 2) - 1;
                const int j_start = i + (len / 2);
                
                long long first_hash = prefix[i_end + 1];
                first_hash -= prefix[i] * base[len / 2];
                first_hash %= MOD;
                first_hash += MOD;
                first_hash %= MOD;
                
                long long second_hash = prefix[i + len];
                second_hash -=  prefix[j_start] * base[len / 2];
                second_hash %= MOD;
                second_hash += MOD;
                second_hash %= MOD;
                
                if (first_hash == second_hash) visited.insert(first_hash);
            }
            answer += visited.size();
            visited.clear();
        }
        
        return answer;
    }
};
