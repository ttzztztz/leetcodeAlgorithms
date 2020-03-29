class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int N = rating.size();
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (rating[i] > rating[j] && rating[j] > rating[k]) answer++;
                    else if (rating[i] < rating[j] && rating[j] < rating[k]) answer++;
                }
            }
        }
        return answer;
    }
};
