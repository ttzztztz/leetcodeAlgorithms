class Solution {
public:
    /**
     * @param cost: The cost of each interviewer
     * @return: The total cost of all the interviewers.
     */
    int TotalCost(vector<vector<int>> &cost) {
        int answer = 0;
        
        sort(cost.begin(), cost.end(), [](const auto& $1, const auto& $2)->bool {
            return $1[0] - $1[1] > $2[0] - $2[1];
        });
        
        const int N = cost.size();
        for (int i = 0; i < N; i++) {
            if (i < N / 2) {
                answer += cost[i][1];
            } else {
                answer += cost[i][0];
            }
        }
        
        return answer;
    }
};
