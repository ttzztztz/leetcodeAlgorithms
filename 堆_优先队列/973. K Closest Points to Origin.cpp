class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // dist, x, y
        typedef tuple<int, int, int> State;
        priority_queue<State, vector<State>, less<>> heap; // big heap
        for (int i = 0; i < points.size(); i++) {
            heap.emplace(dist(points[i][0], points[i][1]), points[i][0], points[i][1]);
            if (heap.size() > k) heap.pop();
        }

        vector<vector<int>> ans;
        while (!heap.empty()) {
            auto[_, x, y] = heap.top();
            heap.pop();
            ans.push_back(vector<int>{ x, y });
        }
        return ans;
    }
private:
    int dist(int x, int y) {
        return x * x + y * y;
    }
};