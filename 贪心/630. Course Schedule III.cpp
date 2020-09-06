class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int time = 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& $1, const vector<int>& $2)->bool {
            return $1[1] < $2[1];
        });
        
        const int N = courses.size();
        priority_queue<int, vector<int>, less<>> heap;
        for (int i = 0; i < N; i++) {
            if (time + courses[i][0] <= courses[i][1]) {
                time += courses[i][0];
                heap.push(courses[i][0]);
            } else if (heap.size() && heap.top() > courses[i][0]) {
                time -= heap.top();
                heap.pop();
                
                time += courses[i][0];
                heap.push(courses[i][0]);
            }
        }
        return heap.size();
    }
};
