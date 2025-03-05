class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<vector<int>> intervals;
        for (const string& word : words) {
            int last_pos = 0;
            while ((last_pos = s.find(word, last_pos)) != string::npos) {
                const int end_pos = last_pos + word.size() - 1;
                intervals.push_back(vector<int>{ last_pos, end_pos });
                last_pos += 1;
            }
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            while (i + 1 < intervals.size() && max(l, intervals[i + 1][0]) - 1 <= min(r, intervals[i + 1][1])) {
                l = min(l, intervals[i + 1][0]);
                r = max(r, intervals[i + 1][1]);
                i++;
            }
            merged.push_back(vector<int>{ l, r });
        }

        string ans;
        for (int pos = 0, i = 0; i < s.size(); i++) {
            if (pos < merged.size() && merged[pos][0] == i) ans += "<b>";
            ans += s[i];
            if (pos < merged.size() && merged[pos][1] == i) ans += "</b>", pos++;
        }
        return ans;
    }
};