class Solution {
public:
    /**
     * @param str: a string for calculating.
     * @param k: the length of special substring.
     * @return: return the number of special substrings.
     */
    int specialSubstringCount(string &str, int k) {
        // write your code here.
        int answer = 0;
        const int N = str.size();
        unordered_map<char, int> appear;
        for (int i = 0; i < k; i++) appear[str[i]]++;
        
        auto check = [&]() -> bool {
            int repeatCnt = 0;
            for (auto& x : appear) {
                if (x.second >= 2) repeatCnt++;
            }
            return repeatCnt == 1;
        };
        
        if (check()) answer++;
        for (int l = 0, r = k; r < N; l++, r++) {
            appear[str[r]]++;
            appear[str[l]]--;
            
            if (check()) answer++;
        }
        
        return answer;
    }
};
