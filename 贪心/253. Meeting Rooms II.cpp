class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        const int n = intervals.size();
        
        priority_queue<int, vector<int>, greater<>> heap;
        for (int i = 0; i < n; i++) {
            const int l = intervals[i][0], r = intervals[i][1] - 1;
            
            if (heap.empty() || l <= heap.top()) {
                heap.push(r);
            } else {
                heap.pop();
                heap.push(r);
            }
        }
        return heap.size();
    }
};
