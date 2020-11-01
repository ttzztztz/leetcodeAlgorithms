iclass Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int n = heights.size();
        
        int ans = 0;
        
        priority_queue<int, vector<int>, less<>> heap;
        for (int i = 1; i < n; i++) {
            const int h = heights[i];
            const int delta = h - heights[i - 1];
            
            if (delta <= 0) {
                ans = max(ans, i);
            } else {
                if (bricks >= delta) {
                    bricks -= delta;
                    heap.push(delta);
                    ans = max(ans, i);
                } else if (ladders > 0) {
                    ans = max(ans, i);
                    if (!heap.empty() && bricks + heap.top() >= delta) {
                        bricks += heap.top();
                        heap.pop();
                        ladders--;
                    }
                    
                    if (bricks >= delta) {
                        bricks -= delta;
                        heap.push(delta);
                    } else {
                        ladders--;
                    }
                } else {
                    break;
                }
            }
        }
        
        return ans;
    }
};
