class Solution {
public:
    int maxPower(string s) {
        int answer = 0;
        unordered_map<char, int> appear;
        const int N = s.size();
        
        for (int left = 0, right = 0; right < N; right++) {
            appear[s[right]]++;
            while (appear.size() > 1) {
                appear[s[left]]--;
                if (appear[s[left]] == 0) appear.erase(s[left]);
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        
        return answer;
    }
};
