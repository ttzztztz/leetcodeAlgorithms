class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const auto& lhs, const auto& rhs) -> bool {
            return lhs[1] < rhs[1];
        });
        
        const int n = courses.size();
        priority_queue<int, vector<int>, less<>> heap;
        int total_time = 0;
        for (int i = 0; i < n; i++) {
            const int duration = courses[i][0], last_day = courses[i][1];
            if (total_time + duration <= last_day) {
                total_time += duration;
                heap.push(duration);
            } else if (!heap.empty() && heap.top() > duration) {
                total_time -= heap.top();
                heap.pop();
                
                total_time += duration;
                heap.push(duration);
            }
        }
        return heap.size();
    }
};