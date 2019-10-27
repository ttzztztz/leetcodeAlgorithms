class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        priority_queue<int, vector<int>, less<>> heap;
        int answer = 0;

        int current = startFuel;
        for (int i = 0; i < stations.size(); i++) {
            while (current < stations[i][0] && !heap.empty()) {
                current += heap.top();
                heap.pop();
                answer++;
            }

            if (current < stations[i][0]) {
                return -1;
            }

            heap.push(stations[i][1]);

        }

        return answer;
    }
};