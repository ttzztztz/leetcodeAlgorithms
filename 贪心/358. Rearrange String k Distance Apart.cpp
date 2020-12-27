class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char, int> last;
        for (char ch = 'a'; ch <= 'z'; ch++) last[ch] = -(k + 1);
        
        typedef pair<int, char> State;
        priority_queue<State, vector<State>, less<>> heap;
        unordered_map<char, int> appear;
        for (const char ch : s) appear[ch]++;
        for (auto [ch, cnt] : appear) heap.emplace(cnt, ch);
        
        string ans;
        int idx = 0;
        while (!heap.empty()) {
            vector<State> nxt;
            bool valid = false;
            
            while (!heap.empty()) {
                auto [cnt, ch] = heap.top();
                heap.pop();
                
                if (idx - last[ch] >= k) {
                    ans += ch;
                    cnt--;
                    last[ch] = idx;
                    idx++;
                    valid = true;

                    if (cnt > 0) nxt.emplace_back(cnt, ch);
                    break;
                } else {
                    nxt.emplace_back(cnt, ch);
                }
            }
            
            if (!valid) return "";
            for (const auto& nxt_state : nxt) heap.push(nxt_state);
        }
        return ans;
    }
};
