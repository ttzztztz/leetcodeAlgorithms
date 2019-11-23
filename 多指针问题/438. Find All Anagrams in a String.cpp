class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        const int S = s.size(), P = p.size();
        unordered_map<char, int> appearCount;
        for (const char& ch : p) {
            appearCount[ch]++;
        }

        unordered_map<char, int> currentAppearCount;
        int left = 0, right = 0, need = appearCount.size();
        for (right = 0; right < P; right++) {
            if (appearCount.count(s[right])) {
                currentAppearCount[s[right]]++;

                if (currentAppearCount[s[right]] == appearCount[s[right]]) {
                    need--;
                }
            }
        }

        right--;
        while (right <= S) {
            if (need == 0) {
                answer.push_back(left);
            }
            if (right == S) {
                break;
            }

            if (appearCount.count(s[left])) {
                if (currentAppearCount[s[left]] == appearCount[s[left]]) {
                    need++;
                }
                currentAppearCount[s[left]]--;
            }

            left++;

            right++;
            if (appearCount.count(s[right])) {
                currentAppearCount[s[right]]++;
                if (currentAppearCount[s[right]] == appearCount[s[right]]) {
                    need--;
                }
            }
        }

        return answer;
    }
};