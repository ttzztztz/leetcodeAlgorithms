class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            vector<vector<int>> answer = {newInterval};
            return answer;
        }

        int left = newInterval[0], right = newInterval[1];
        int leftPtr = 0, rightPtr = intervals.size() - 1;
        auto it = std::lower_bound(intervals.begin(), intervals.end(), newInterval, [](const vector<int>& $1, const vector<int>& $2)->bool {
            return $1[0] < $2[0];
        });
        if (it != intervals.begin()) {
            it--;
        }

        while (it != intervals.end()) {
            const vector<int>& interval = *it;
            if (interval[1] < left) {
                it++;
                continue;
            }

            if (right < interval[0]) {
                break;
            }

            left = std::min(left, interval[0]);
            right = std::max(right, interval[1]);
            it = intervals.erase(it);
        }

        vector<int> addInterval = {left, right};
        intervals.insert(it, addInterval);
        return intervals;
    }
};