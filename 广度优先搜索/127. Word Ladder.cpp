class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) wordList.push_back(beginWord);
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        const int begin_idx = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        const int end_idx = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        const int word_cnt = wordList.size();
        vector<vector<int>> edges(word_cnt);
        for (int i = 0; i < word_cnt; i++) for (int j = i + 1; j < word_cnt; j++) {
            if (can_transform(wordList[i], wordList[j])) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }

        vector<bool> visited(word_cnt, false);
        deque<int> q = { begin_idx };
        visited[begin_idx] = true;
        int ans = 1;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                const int idx = q.front();
                if (end_idx == idx) return ans;
                q.pop_front();

                for (int nxt : edges[idx]) {
                    if (visited[nxt]) continue;
                    if (end_idx == nxt) return ans + 1;

                    visited[nxt] = true;
                    q.push_back(nxt);
                }
            }
            ans++;
        }
        return 0;
    }
private:
    bool can_transform(const string& str1, const string& str2) {
        if (str1.size() != str2.size()) return false;

        bool diff = false;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                if (diff) return false;
                diff = true;
            }
        }
        return diff == true;
    }
};