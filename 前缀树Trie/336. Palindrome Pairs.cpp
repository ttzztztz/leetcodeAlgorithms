class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
    vector<int> flag;
    vector<int> suffix;
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<string> reversed_words = words;
        const int N = words.size();
        for (string& s : reversed_words) reverse(s.begin(), s.end());
        vector<int> selfPalindrome;
        vector<int> blank;

        vector<vector<int>> answer;
        root = new TrieNode();
        
        for (int i = 0; i < N; i++) {
            if (words[i].empty()) blank.push_back(i);
            insert(i, reversed_words[i]);
            if (isPalindrome(words[i], 0, words[i].size() - 1)) selfPalindrome.push_back(i);
        }

        for (int i = 0; i < N; i++) {
            const string& word = words[i];
            
            TrieNode* cur = root;
            // case 1
            int j = 0;
            for (; j < word.size(); j++) {
                if (isPalindrome(word, j, word.size() - 1)) {
                    for (int f : cur->flag) {
                        if(i != f) answer.push_back(vector<int>{i, f});
                    }
                }
                
                cur = cur->next[word[j]];
                if (cur == nullptr) break;
            }
            
            // case 2
            if (j == word.size() && cur != nullptr) {
                for (int f : cur->suffix) {
                    if (i != f) answer.push_back(vector<int>{i, f});
                }
            }
        }
        
        return answer;
    }
private:
    TrieNode* root;
    bool isPalindrome(const string& str, int i, int j) {
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++, j--;
        }
        return true;
    }
    void insert(const int i, const string& str) {
        const int N = str.size();
        TrieNode* cur = root;
        if (isPalindrome(str, 0, str.size() - 1)) cur->suffix.push_back(i);
        
        for (int j = 0; j < N; j++) {
            if (!cur->next.count(str[j])) cur->next[str[j]] = new TrieNode();
            cur = cur->next[str[j]];
            
            if (isPalindrome(str, j + 1, N - 1)) {
                cur->suffix.push_back(i);
            }
        }
        cur->flag.push_back(i);
    }
    TrieNode* find(const string& str, int i, int j) {
        TrieNode* cur = root;
        while (i <= j) {
            cur = cur->next[str[i]];
            if (cur == nullptr) return nullptr;
            i++;
        }
        return cur;
    }
};
