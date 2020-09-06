class Solution {
public:
    /**
     * @param deadends: the list of deadends
     * @param target: the value of the wheels that will unlock the lock
     * @return: the minimum total number of turns 
     */
    int openLock(vector<string> &deadends, string &target) {
        unordered_set<string> v, visited;
        for (const string& str : deadends) v.insert(str);
        
        int answer = 0;
        if (v.count("0000")) return -1;
        deque<string> q = {"0000"};
        
        auto canReach = [&](const string& old, const string& nxt, int d) -> bool {
            string cur = old;
            for (int k = old[d] - '0' - 1, i = 0; i < 10; k = (k + 9) % 10, i++) {
                cur[d] = k + '0';
                if (v.count(cur)) break;
                if (cur == nxt) return true;
            }
            
            for (int k = old[d] - '0' + 1, i = 0; i < 10; k = (k + 1) % 10, i++) {
                cur[d] = k + '0';
                if (v.count(cur)) break;
                if (cur == nxt) return true;
            }
            
            return false;
        };
        
        while (!q.empty()) {
            int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                string str = q.front();
                q.pop_front();
                
                if (v.count(str)) continue;
                if (str == target) return answer;
                visited.insert(str);
                
                for (int i = 0; i < 4; i++) {
                    string s = str;
                    const int t = str[i] - '0';
                    int j = (t + 9) % 10;
                    s[i] = '0' + j;
                        
                    if (!v.count(s) && !visited.count(s) && canReach(str, s, i)) {
                        if (s == target) return answer + 1;
                            
                        visited.insert(s);
                        q.push_back(s);
                    }
                    
                    j = (t + 1) % 10;
                    s[i] = '0' + j;
                    if (!v.count(s) && !visited.count(s) && canReach(str, s, i)) {
                        if (s == target) return answer + 1;
                            
                        visited.insert(s);
                        q.push_back(s);
                    }
                }
            }
            answer++;
        }
        
        return -1;
    }
};
