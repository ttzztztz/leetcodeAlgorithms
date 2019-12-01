class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> answer;

        for (const vector<int>& interval : intervals) {
            int left = max(interval[0], toBeRemoved[0]), right = min(interval[1], toBeRemoved[1]);
            if (left <= right) {
                if (interval[0] < toBeRemoved[0]) {
                    answer.push_back(vector<int>{interval[0], toBeRemoved[0]});
                }

                if (toBeRemoved[1] <= interval[1]) {
                    answer.push_back(vector<int>{toBeRemoved[1], interval[1]});
                }

            } else {
                answer.push_back(interval);
            }
        }

        return answer;
    }
};