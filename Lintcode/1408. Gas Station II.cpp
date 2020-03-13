class Solution {
public:
    /**
     * @param target: The target distance
     * @param original: The original gas
     * @param distance: The distance array
     * @param apply: The apply array
     * @return: Return the minimum times
     */
    typedef tuple<int, int, int> State; // gas time, position, have gas
    int getTimes(int target, int original, vector<int> &distance, vector<int> &apply) {
        const int M = distance.size();
        
        int ptr = 0;
        for (; ptr < M; ptr++) {
            if (distance[ptr] > target) break;
        }
        distance.resize(ptr);
        apply.resize(ptr);
        
        const int N = distance.size();
        State start = make_tuple(0, 0, original);
        unordered_set<string> visited{hash(start)};
        priority_queue<State, vector<State>, greater<>> heap;
        heap.emplace(start);
        
        while (!heap.empty()) {
            int gasTime, position, have;
            tie(gasTime, position, have) = heap.top();
            heap.pop();
            
            if (have < 0) continue;
            if (position == N + 1) return gasTime;
            
            const int d = (position == N ? target : distance[position]) - (position == 0 ? 0 : distance[position - 1]);
            
            // gas
            if (position >= 1 && !visited.count(hash(gasTime + 1, position + 1, have - d + apply[position - 1]))) {
                visited.insert(hash(gasTime + 1, position + 1, have - d + apply[position - 1]));
                
                heap.emplace(gasTime + 1, position + 1, have - d + apply[position - 1]);
            }
            // no gas
            if (!visited.count(hash(gasTime, position + 1, have - d))) {
                visited.insert(hash(gasTime, position + 1, have - d));
                heap.emplace(gasTime, position + 1, have - d);
            }
        }
        
        return -1;
    }
private:
    string hash(const State& s) {
        string answer;
        answer += to_string(get<0>(s));
        answer += ",";
        answer += to_string(get<1>(s));
        answer += ",";
        answer += to_string(get<2>(s));
        return answer;
    }
    string hash(int gasTime, int position, int have) {
        string answer;
        answer += to_string(gasTime);
        answer += ",";
        answer += to_string(position);
        answer += ",";
        answer += to_string(have);
        return answer;
    }
};
