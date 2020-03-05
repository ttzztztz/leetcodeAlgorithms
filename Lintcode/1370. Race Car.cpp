class Solution {
public:
    string hash(int offset, int speed) {
        string answer;
        
        answer += to_string(offset);
        answer += ',';
        answer += to_string(speed);
        
        return answer;
    }
    int racecar(int target) {
        unordered_set<string> visited;
        
        deque<pair<int, int>> queue;
        queue.emplace_back(0, 1);
        int answer = 0;
        while (!queue.empty()) {
            int cnt = queue.size();
            for (int _ = 0; _ < cnt; _++) {
                int offset, speed;
                if (offset == target) return answer;
                tie(offset, speed) = queue.front();
                queue.pop_front();
                
                // A
                {
                    const int next_offset = offset + speed, next_speed = speed * 2;
                    if (next_offset == target) return answer + 1;
                    if (abs(next_speed) < 2 * target && abs(next_offset) < 2 * target) {
                        queue.emplace_back(next_offset, next_speed);
                    }
                }
                
                // R
                {
                    const int next_offset = offset, next_speed = speed > 0 ? -1 : 1;
                    if (next_offset == target) return answer + 1;
                    
                    const string h = hash(next_offset, next_speed);
                    if (!visited.count(h)) {
                        queue.emplace_back(next_offset, next_speed);
                        visited.insert(h);
                    }
                }
            }
            answer++;
        }
        return -1; // never reach this branch
    }
};
