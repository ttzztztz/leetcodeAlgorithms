class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> q(students.begin(), students.end());
        for (int i = 0; i < sandwiches.size(); i++) {
            int cnt = 0;
            
            bool ok = false;
            const int n = q.size();
            while (q.front() != sandwiches[i]) {
                if (cnt >= n) break;
                const int t = q.front();
                q.pop_front();
                q.push_back(t);
                cnt++;
            }
            
            if (cnt >= n) return q.size();
            q.pop_front();
        }
        return 0;
    }
};
