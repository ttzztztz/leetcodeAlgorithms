class TrieNode {
public:
    bool flag;
    unordered_map<char, int> next;
    TrieNode() : flag(false) {};
};

class Solution {
public:
    TrieNode node[600005];
    int nodeOffset;
    void insert(const string& str) {
        int current = 0;

        for (int i = 0; i < str.size(); i++) {
            const char ch = str[i];

            if (!node[current].next.count(ch)) {
                node[current].next[ch] = nodeOffset;
                current = nodeOffset++;
            } else {
                current = node[current].next[ch];
            }
        }

        node[current].flag = true;
    }
    bool find(const string& str, int offset, int count) {
        const int N = str.size();
        if (offset == N) {
            return count >= 2;
        }

        int current = 0;
        for (int i = offset; i < N; i++) {
            if (!node[current].next.count(str[i])) {
                return false;
            } else {
                current = node[current].next[str[i]];
                if (node[current].flag && find(str, i + 1, count + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        nodeOffset = 1;

        for (const string& word : words) {
            insert(word);
        }

        vector<string> answer;
        for (const string& word : words) {
            if (find(word, 0, 0)) {
                answer.push_back(word);
            }
        }
        return answer;
    }
};