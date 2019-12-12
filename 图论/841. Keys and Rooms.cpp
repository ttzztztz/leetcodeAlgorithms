class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 0, N = rooms.size();
        vector<bool> visited = vector<bool>(N, false);

        vector<int> stack;
        stack.push_back(0);
        while (!stack.empty()) {
            const int u = stack.back();
            stack.pop_back();

            if (visited[u]) {
                continue;
            }

            count++;
            visited[u] = true;
            for (const int key : rooms[u]) {
                stack.push_back(key);
            }
        }


        return count == N;
    }
};