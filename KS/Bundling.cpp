#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    bool flag;
    unordered_map<int, TrieNode *> next;
    int size;
    TrieNode() : flag(false), size(0) {};
};

TrieNode *root;

void insert(const string& word) {
    TrieNode *curr = root;
    curr->size++;

    for (const char ch : word) {
        if (!curr->next.count(ch)) {
            curr->next[ch] = new TrieNode();
        }
        curr = curr->next[ch];
        curr->size++;
    }
    curr->flag = true;
}

int dfs(TrieNode* u, int size, int prefix) {
    int mx = 0;

    vector<TrieNode*> allNext;
    for (auto& p : u->next) {
        if (p.second == nullptr) continue;
        allNext.emplace_back(p.second);
    }

    sort(allNext.begin(), allNext.end(), [](const auto& $1, const auto& $2)->bool {
        return $1->size > $2->size;
    });

    int ptr = 0;
    while (size > 0 && ptr < allNext.size()) {
        const int use = min(size, allNext[ptr]->size);
        bool usedAll = use == size;
        size -= use;

        if (usedAll) {
            mx = dfs(allNext[ptr], use, prefix + 1);
            allNext[ptr]->size -= use;
        } else {
            allNext[ptr]->size -= use;
            return prefix;
        }

        ptr++;
    }

    return max(mx, prefix);
}

void deleteAll(TrieNode* u) {
    if (u == nullptr) return;
    for (auto& p : u->next) {
        deleteAll(p.second);
    }
    delete u;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;

        deleteAll(root);
        root = new TrieNode();

        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            insert(s);
        }

        const int groupCount = N / K;
        for (int i = 0; i < groupCount; i++) {
            answer += dfs(root, K, 0);
        }
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
