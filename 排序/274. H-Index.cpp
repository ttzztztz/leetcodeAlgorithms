class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int N = citations.size();
        sort(citations.begin(), citations.end(), greater<>());
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            const int number = citations[i - 1];
            if (number >= i) {
                answer = max(answer, min(number, i));
            } else {
                break;
            }
        }
        return answer;
    }
};