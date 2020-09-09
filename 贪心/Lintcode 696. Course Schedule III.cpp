class Solution {
public:
    /**
     * @param courses: duration and close day of each course
     * @return: the maximal number of courses that can be taken
     */
    int scheduleCourse(vector<vector<int>> &courses) {
        int answer = 0;
        sort(courses.begin(), courses.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[1] < $2[1];
        });
        
        const int n = courses.size();
        int ttl = 0;
        priority_queue<int, vector<int>, less<>> heap;
        for (int i = 0; i < n; i++) {
            const int t = courses[i][0], d = courses[i][1];

            if (ttl + t <= d) {
                ttl += t;
                heap.push(t);
                answer = max(answer, (int) heap.size());
            } else if (!heap.empty()) {
                const int v = heap.top();
                if (v > t) {
                    ttl -= v;
                    ttl += t;
                    heap.pop();
                    heap.push(t);
                }
            }
        }
        
        return answer;
    }
};