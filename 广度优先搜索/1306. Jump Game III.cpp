class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        vector<bool> visited(n, false);
        deque<int> q = {start};
        while (!q.empty()) {
            auto i = q.front();
            q.pop_front();
            visited[i] = true;
            if (arr[i] == 0) return true;
            
            if (i - arr[i] >= 0 && !visited[i - arr[i]]) q.push_back(i - arr[i]);
            if (i + arr[i] < n && !visited[i + arr[i]]) q.push_back(i + arr[i]);
        }
        return false;
    }
};