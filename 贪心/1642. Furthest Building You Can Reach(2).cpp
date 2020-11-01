class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int n = heights.size();
        if (n <= 1) return n;
        
        priority_queue<int, vector<int>, greater<>> heap;
        for (int i = 1; i < n; i++) {
            const int h = heights[i];
            const int delta = h - heights[i - 1];
            if (delta <= 0) continue;
            
            heap.push(delta);
            if (ladders > 0) {
                ladders--;
            } else {
                if (heap.empty() || bricks - heap.top() < 0) return i - 1;
                bricks -= heap.top();
                heap.pop();
            }
        }
        return n - 1;
    }
};
