class Solution {
public:
    int N = 0, M = 0;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x <= N && y <= M;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        vector<int> allX, allY;
        for (const vector<int>& block : blocked) {
            allX.push_back(block[0]), allY.push_back(block[1]);
            if (block[0] - 1 >= 0) allX.push_back(block[0] - 1);
            // if (block[1] - 1 >= 0) allY.push_back(block[1] - 1);
            
            // if (block[0] + 1 < 1e6) allX.push_back(block[0] + 1);
            if (block[1] + 1 < 1e6) allY.push_back(block[1] + 1);
        }
        allX.push_back(source[0]), allX.push_back(target[0]);
        allY.push_back(source[1]), allY.push_back(target[1]);
        
        sort(allX.begin(), allX.end()), sort(allY.begin(), allY.end());
        auto endX = unique(allX.begin(), allX.end());
        auto endY = unique(allY.begin(), allY.end());
        
        for (vector<int>& block : blocked) {
            block[0] = lower_bound(allX.begin(), endX, block[0]) - allX.begin();
            block[1] = lower_bound(allY.begin(), endY, block[1]) - allY.begin();
            
            N = max(N, block[0]), M = max(M, block[1]);
        }
        source[0] = lower_bound(allX.begin(), endX, source[0]) - allX.begin();
        source[1] = lower_bound(allY.begin(), endY, source[1]) - allY.begin();
        target[0] = lower_bound(allX.begin(), endX, target[0]) - allX.begin();
        target[1] = lower_bound(allY.begin(), endY, target[1]) - allY.begin();
        N = max(N, source[0]), M = max(M, source[1]);
        N = max(N, target[0]), M = max(M, target[1]);
        
        set<pair<int, int>> visited;
        visited.emplace(source[0], source[1]);
        
        deque<pair<int, int>> queue;
        queue.emplace_back(source[0], source[1]);
        
        const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        while (!queue.empty()) {
            int x, y;
            tie(x, y) = queue.front();
            queue.pop_front();
            
            if (x == target[0] && y == target[1]) {
                return true;
            }
            
            for (int k = 0; k < 4; k++) {
                const int nextX = x + dx[k], nextY = y + dy[k];
                
                if (pointValid(nextX, nextY) && !visited.count({nextX, nextY}) && find(blocked.begin(), blocked.end(), vector<int>{nextX, nextY}) == blocked.end()) {
                    visited.emplace(nextX, nextY);
                    queue.emplace_back(nextX, nextY);
                }
                
                if (nextX == target[0] && nextY == target[1]) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
