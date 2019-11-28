class Solution {
public:
    int count(int* statics) {
        int total = 0;

        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            total += statics[i];
            maxCount = max(maxCount, statics[i]);
        }

        return total - maxCount;
    }

    int characterReplacement(string s, int k) {
        int answer = 0;
        const int N = s.size();

        int left = 0, right = 0, statics[26];
        memset(statics, 0, sizeof(statics));
        while (right < N) {
            const int index = s[right] - 'A';
            statics[index]++;

            while (count(statics) > k) {
                statics[s[left] - 'A']--;
                left++;
            }

            answer = max(right - left + 1, answer);
            right++;
        }
        return answer;
    }
};