class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;

        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>> heap;
        for (const auto& interval : intervals) {
            const int start = interval[0];
            const int end = interval[1];

            while (!heap.empty() && heap.top() <= start) heap.pop();
            heap.push(end);
            ans = max<int>(ans, heap.size());
        }
        return ans;
    }
};