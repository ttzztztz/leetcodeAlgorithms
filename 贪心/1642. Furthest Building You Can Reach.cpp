class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int n = heights.size();
        priority_queue<int, vector<int>, greater<>> heap;
        for (int i = 1; i < n; i++) {
            const int d = heights[i] - heights[i - 1];
            
            if (d > 0) {
                heap.push(d);
                if (heap.size() > ladders) {
                    bricks -= heap.top();
                    heap.pop();
                }
                
                if (bricks < 0) {
                    return i - 1;
                }
            }
        }
        return n - 1;
    }
};