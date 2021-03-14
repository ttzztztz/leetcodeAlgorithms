class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        typedef tuple<double, int, int> State;
        const int n = classes.size();
        priority_queue<State, vector<State>, less<>> heap;
        for (auto& cls : classes) {
            heap.emplace(fac(cls[0], cls[1]), cls[0], cls[1]);
        }
        
        for (int i = 0; i < extraStudents; i++) {
            auto [r, p, t] = heap.top();
            heap.pop();
            
            p++, t++;
            heap.emplace(fac(p, t), p, t);
        }
        
        double ans = 0.0;
        while (!heap.empty()) {
            auto [r, p, t] = heap.top();
            heap.pop();
            ans += ((1.0 * p) / (1.0 * t)) / (1.0 * n);
        }
        return ans;
    }
private:
    double fac(int pass, int total) {
        double r1 = (1.0 * pass) / (1.0 * total);
        double r2 = (1.0 * (pass + 1)) / (1.0 * (total + 1));
        return r2 - r1;
    }
};
