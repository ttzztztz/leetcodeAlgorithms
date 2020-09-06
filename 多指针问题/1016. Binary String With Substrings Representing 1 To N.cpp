class Solution {
public:
    bool queryString(string S, int N) {
        unordered_set<long long> val;
        
        auto ins = [&](long long x) -> void {
            if (x <= N) val.insert(x);
        };
        
        const int M = S.size();
        for (int len = 1; len <= min(30, M); len++) {
            string cur;
            int i = 0, j = i + len - 1;
            for (int k = i; k <= j; k++) cur.push_back(S[k]);
            ins(convert(cur));
            j++;
            
            while (j < M) {
                cur.erase(cur.begin());
                cur += S[j];
                
                ins(convert(cur));
                i++, j++;
            }
        }
        
        for (int i = 1; i <= N; i++) {
            if (!val.count((long long) i)) return false;
        }
        return true;
    }
private:
    long long convert(const string& str) {
        long long answer = 0;
        long long sft = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == '1') answer |= 1ll << sft;
            sft++;
        }
        return answer;
    }
};
