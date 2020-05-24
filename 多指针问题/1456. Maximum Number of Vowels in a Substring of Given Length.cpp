class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> ok = {'a', 'e', 'i', 'o', 'u'};
        
        const int N = s.size();
        unordered_map<char, int> appear;
        
        auto cnt = [&]() -> int {
            int tmp = 0;
            for (const auto& p : appear) {
                if (ok.count(p.first)) tmp += p.second;
            }
            return tmp;
        };
        
        for (int i = 0; i < k; i++) {
            appear[s[i]]++;
        }
        int answer = 0;
        answer = max(answer, cnt());
        
        for (int left = 0, right = k; right < N; left++, right++) {
            appear[s[right]]++;
            appear[s[left]]--;
            
            answer = max(answer, cnt());
        }
        return answer;
    }
};
