class Solution {
public:
    unordered_set<string> patternSet;
    unordered_map<string, string> parent;
    vector<string> answer;
    string find(string u) {
        if (parent[u] != u) {
            return parent[u] = find(parent[u]);
        } else {
            return u;
        }
    }
    void merge(string u, string v) {
        string parentU = find(u), parentV = find(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
        }
    }
    void dfs(string& text, int index) {
        if (index > text.size()) {
            answer.push_back(text);
            return;
        }

        int i = index;
        string temp = text, word;
        for (i = index; i < text.size() && text[i] != ' '; i++) {
            word += text[i];
        }

        i++;
        dfs(text, i);

        if (patternSet.count(word)) {
            for (const string& p : patternSet) {
                if (word != p && find(p) == find(word)) {
                    text.replace(index, word.size(), p);
                    dfs(text, i - word.size() + p.size());
                    text = temp;
                }
            }
        }
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for (const vector<string>& s : synonyms) {
            parent[s[0]] = s[0];
            parent[s[1]] = s[1];
        }

        for (const vector<string>& s : synonyms) {
            patternSet.insert(s[0]);
            patternSet.insert(s[1]);
            merge(s[0], s[1]);
        }

        dfs(text, 0);
        sort(answer.begin(), answer.end());
        return answer;
    }
};