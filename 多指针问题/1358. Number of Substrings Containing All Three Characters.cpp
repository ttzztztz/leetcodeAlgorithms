class Solution {
public:
    vector<int> occur;
    bool allOccur() {
        return occur[0] >= 1 && occur[1] >= 1 && occur[2] >= 1;
    }
    int numberOfSubstrings(string s) {
        int answer = 0;
        occur = vector<int>(3, 0);
        const int N = s.size();
        int left = 0, right = 0;
        
        while (right < N) {
            occur[s[right] - 'a']++;
            while (allOccur() && occur[s[left] - 'a'] >= 2) {
                occur[s[left] - 'a']--;
                left++;
            }
            
            if (allOccur()) {
                answer += left + 1;
            }
            right++;
        }
        
        return answer;
    }
};
