class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        deque<int> q;
        const int n = status.size();
        vector<int> boxes(n, 0);
        for (int b : initialBoxes) {
            if (status[b] == 1) {
                q.push_back(b);
                boxes[b] = 2;
            } else {
                boxes[b] = 1;
            }
        }
        
        int ans = 0;
        while (!q.empty()) {
            const int u = q.front();
            q.pop_front();
            
            ans += candies[u];
            for (int v : keys[u]) {
                status[v] = 1;
                
                if (boxes[v] == 1 && status[v] == 1) {
                    q.push_back(v);
                    boxes[v] = 2;
                }
            }
            
            for (int v : containedBoxes[u]) {
                if (boxes[v] == 0) boxes[v] = 1;
                
                if (boxes[v] == 1 && status[v] == 1) {
                    q.push_back(v);
                    boxes[v] = 2;
                }
            }
        }
        return ans;
    }
};