class Solution {
public:
    bool isSame(const vector<int>& appear, const vector<int>& current) {
        for (int i = 0; i < 26; i++) {
            if (appear[i] != current[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        const int N = s1.size();
        vector<int> appear(26, 0);
        for (const char& ch : s1) {
            appear[ch - 'a']++;
        }

        vector<int> current(26, 0);
        for (int i = 0; i < N; i++) {
            current[s2[i] - 'a']++;
        }

        if (isSame(appear, current)) {
            return true;
        }

        int left = 0, right = N - 1;
        while (right + 1 < s2.size()) {
            right++;
            current[s2[right] - 'a']++;
            current[s2[left] - 'a']--;
            left++;

            if (isSame(appear, current)) {
                return true;
            }
        }

        return false;
    }
};