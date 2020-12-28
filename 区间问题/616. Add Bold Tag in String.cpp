class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int>> intervals = preprocess(s, dict);
        return generate_answer(s, merge_intervals(intervals));
    }
private:
    string generate_answer(const string& s, const vector<pair<int, int>>& intervals) {
        string ans;
        for (int i = 0, ptr = 0; i < s.size(); i++) {
            if (ptr < intervals.size() && intervals[ptr].first == i) {
                ans += "<b>";
            }
            ans += s[i];
            if (ptr < intervals.size() && intervals[ptr].second - 1 == i) {
                ans += "</b>";
                ptr++;
            }
        }
        return ans;
    }
    
    vector<pair<int, int>> preprocess(const string& s, const vector<string>& dict) {
        vector<pair<int, int>> ans;
        for (const string& word : dict) {
            int ptr = 0;
            while ((ptr = s.find(word, ptr)) != string::npos) {
                ans.emplace_back(ptr, ptr + word.size());
                ptr++;
            }
        }
        return ans;
    }
    
    vector<pair<int, int>> merge_intervals(vector<pair<int, int>>& intervals) {
        const pair<int, int> kInvalid = {-1, -1};
        vector<pair<int, int>> ans;
        
        pair<int, int> cur = kInvalid;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            auto [l, r] = intervals[i];
            
            if (cur == kInvalid) {
                cur = intervals[i];
            } else {
                auto& [_l, _r] = cur;
                if (max(l, _l) <= min(r, _r)) {
                    _l = min(_l, l);
                    _r = max(_r, r);
                } else {
                    ans.push_back(cur);
                    cur = intervals[i];
                }
            }
        }
        
        if (cur != kInvalid) {
            ans.push_back(cur);
        }
        return ans;
    }
};
