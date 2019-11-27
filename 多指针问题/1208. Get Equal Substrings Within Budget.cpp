class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int N = s.size();
        int answer = 0;

        int left = 0, right = 0, currentCost = 0;
        while (right < N) {
            currentCost += abs(t[right] - s[right]);

            while (currentCost > maxCost) {
                currentCost -= abs(t[left] - s[left]);
                left++;
            }
            if (currentCost <= maxCost) {
                answer = max(right - left + 1, answer);
            }

            right++;
        }

        return answer;
    }
};