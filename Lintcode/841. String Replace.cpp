class Solution {
public:
    vector<long long> base;
    int MOD = 1e9+7, seed = 33;
    int hash(const string& str) {
        const int N = str.size();
        long long answer = 1;
        for (int i = 0; i < N; i++) {
            answer *= seed;
            answer += str[i] - 'a';
            answer %= MOD;
        }
        return answer;
    }
    void init(int maxLen) {
        base.push_back(1);
        for (int i = 1; i <= maxLen + 5; i++) {
            long long cur = base[i - 1];
            cur *= seed;
            cur %= MOD;
            base.push_back(cur);
        }
    }
    string stringReplace(vector<string> &a, vector<string> &b, string &s) {
        int maxLen = s.size();
        for (int i = 0; i < a.size(); i++) {
            maxLen = max(maxLen, (int) a[i].size());
        }
        init(maxLen);
        
        vector<int> allHashA;
        for (int i = 0; i < a.size(); i++) {
            long long tmp = hash(a[i]) - base[a[i].size()];
            tmp %= MOD;
            tmp += MOD;
            tmp %= MOD;

            allHashA.push_back(tmp);
        }
        vector<int> prefixSum{1};
        
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            long long cur = prefixSum[i];
            
            cur *= seed;
            cur += s[i] - 'a';
            cur %= MOD;
            
            prefixSum.push_back(cur);
        }
        
        for (int i = 0; i < N; i++) {
            int maxLen = 0, index = 0;
            
            for (int k = 0; k < a.size(); k++) {
                if (i + a[k].size() > N) continue;
                
                long long currentHash = prefixSum[i + a[k].size()];
                currentHash -= prefixSum[i] * base[a[k].size()];
                currentHash %= MOD;
                currentHash += MOD;
                currentHash %= MOD;
                
                if (allHashA[k] == currentHash && a[k].size() > maxLen) {
                    maxLen = a[k].size();
                    index = k;
                }
            }
            
            if (maxLen != 0) {
                const string& newStr = b[index];
                
                for (int j = 0; j < newStr.size(); j++) s[i + j] = newStr[j];
                i += newStr.size() - 1;
            }
        }
        
        return s;
    }
};
