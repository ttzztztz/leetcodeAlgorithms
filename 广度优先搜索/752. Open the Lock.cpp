class Solution {
public:
    string nextState(string prev, int digit) {
        int d = prev[digit] - '0';
        d++;
        if (d >= 10) d -= 10;
        prev[digit] = d + '0';
        return prev;
    }
    string prevState(string prev, int digit) {
        int d = prev[digit] - '0';
        d--;
        if (d < 0) d += 10;
        prev[digit] = d + '0';
        return prev;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet;
        for (const string& s : deadends) {
            deadendSet.insert(s);
        }

        if (deadendSet.count("0000") || deadendSet.count(target)) return -1;

        unordered_set<string> visited;
        deque<pair<string, int>> queue;
        queue.emplace_back("0000", 0);
        visited.insert("0000");

        while (!queue.empty()) {
            string state;
            int dist;
            tie(state, dist) = queue.front();
            queue.pop_front();

            if (state == target) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                string next = nextState(state, i);
                if (!deadendSet.count(next) && !visited.count(next)) {
                    visited.insert(next);
                    queue.emplace_back(next, dist + 1);
                }
                string prev = prevState(state, i);
                if (!deadendSet.count(prev) && !visited.count(prev)) {
                    visited.insert(prev);
                    queue.emplace_back(prev, dist + 1);
                }
            }
        }

        return -1;
    }
};