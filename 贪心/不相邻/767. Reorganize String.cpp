class Solution {
public:
    string reorganizeString(string s) {
        string ans;
        const int n = s.size();
        typedef pair<int, char> State;
        
        unordered_map<char, int> appear;
        for (const char ch : s) appear[ch]++;
        
        priority_queue<State, vector<State>, less<>> heap;
        for (auto&[k, v] : appear) heap.emplace(v, k);
        
        while (!heap.empty()) {
            auto [cnt1, ch1] = heap.top();
            heap.pop();
            
            if (ans.empty() || ans.back() != ch1) {
                ans += ch1;
                if (cnt1 > 1) heap.emplace(cnt1 - 1, ch1);
            } else if (!heap.empty()) {
                auto [cnt2, ch2] = heap.top();
                heap.pop();
                
                ans += ch2;
                heap.emplace(cnt1, ch1);
                if (cnt2 > 1) heap.emplace(cnt2 - 1, ch2);
            } else {
                return "";
            }
        }
        
        return ans;
    }
};