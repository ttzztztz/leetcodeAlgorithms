class Solution {
public:
    bool haveOverlap(const vector<int>& $1, const vector<int>& $2) {
        const int a = max($1[0], $2[0]), b = min($1[1], $2[1]);
        return a < b;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& $1, const vector<int>& $2)->bool {
            if ($1[1] == $2[1]) {
                return $1[0] < $2[0];
            } else {
                return $1[1] < $2[1];
            }
        });
        if (intervals.size() == 0) return 0;
        
        const int N = intervals.size();
        int answer = 0, ptr = 0;
        
        while (ptr < N) {
            int i = ptr + 1;
            for (; i < N; i++) {
                if (haveOverlap(intervals[ptr], intervals[i])) {
                    answer++;
                } else {
                    break;
                }
            }
            
            ptr = i;
        }
        
        return answer;
    }
};
