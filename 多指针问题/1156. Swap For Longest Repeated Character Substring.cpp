class Solution {
public:
    int maxRepOpt1(string text) {
        const int n = text.size();
        unordered_map<char, int> a, cur;
        for (const char ch : text) a[ch]++;
        
        auto needMove = [&]() -> bool {
            if (cur.size() <= 1) return false;
            if (cur.size() >= 3) return true;
            
            for (auto& p : cur) {
                if (p.second == 1) return false;
            }
            return true;
        };
        
        auto calc = [&]() -> int {
            if (cur.empty()) return 0;
            if (cur.size() == 1) return cur.begin()->second;
            
            auto $1 = *cur.begin(), $2 = *(++cur.begin());
            if ($1.second == 1 && $2.second == 1) {
                if (a[$1.first] >= 2 || a[$2.first] >= 2) return 2;
                else return 1;
            } else if ($1.second == 1) {
                return min(a[$2.first], $2.second + 1);
            } else if ($2.second == 1) {
                return min(a[$1.first], $1.second + 1);
            } else return 0;
        };
        
        int answer = 0;
        for (int l = 0, r = 0; r < n; r++) {
            cur[text[r]]++;
            
            while (needMove()) {
                cur[text[l]]--;
                if (cur[text[l]] == 0) {
                    cur.erase(text[l]);
                }
                l++;
            }
            
            answer = max(answer, calc());
        }
        return answer;
    }
};