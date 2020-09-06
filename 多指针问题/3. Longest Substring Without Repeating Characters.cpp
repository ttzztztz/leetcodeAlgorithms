class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.size();
        
        unordered_map<char, int> hm;
        
        auto judge = [&]() -> bool {
            for (auto& p : hm) {
                if (p.second > 1) return true;
            }
            return false;
        };
        
        int answer = 0;
        for (int l = 0, r = 0; r < N; r++) {
            hm[s[r]]++;
            while (judge()) {
                hm[s[l]]--;
                if (hm[s[l]] == 0) hm.erase(s[l]);
                l++;
            }
            answer = max(answer, r - l + 1);
        }
        return answer;
    }
};
