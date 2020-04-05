class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        typedef pair<int, char> State;
        string answer;
        
        char last = 0;
        int lastCount = 0;
        
        priority_queue<State, vector<State>, less<>> heap;
        if (a > 0) heap.emplace(a, 'a');
        if (b > 0) heap.emplace(b, 'b');
        if (c > 0) heap.emplace(c, 'c');
        
        while (!heap.empty()) {
            vector<State> nxt;
            bool filled = false;
            
            while (!heap.empty()) {
                int cnt;
                char ch;
                tie(cnt, ch) = heap.top();
                heap.pop();
                
                if (ch == last && lastCount >= 2) {
                    nxt.emplace_back(cnt, ch);
                } else {
                    cnt--;
                    filled = true;
                    answer += ch;
                    
                    if (ch == last) {
                        lastCount++;
                    } else {
                        last = ch;
                        lastCount = 1;
                    }
                    
                    if (cnt > 0) nxt.emplace_back(cnt, ch);
                }
                
                if (filled) break;
            }
            
            if (!filled) break;
            for (auto p : nxt) heap.push(p);
        }
        return answer;
    }
};
