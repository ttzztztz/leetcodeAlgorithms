class Solution {
public:
    int parent[300005];
    void init() {
        for (int i = 0; i < 300005; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        int parentU = findParent(u), parentV = findParent(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> answer;
        init();

        int mailIndex = 0;
        int answerIndex = 0;

        unordered_map<string, int> mapMailToIndex;
        unordered_map<int, string> mapIndexToMail;
        unordered_map<int, int> mapMailIndexToNameIndex;
        unordered_map<int, int> mapDisjointSetIndexToAnswerIndex;

        for (int i = 0; i < accounts.size(); i++) {
            const vector<string>& account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                if (!mapMailToIndex.count(account[j])) {
                    mapMailToIndex[account[j]] = mailIndex;
                    mapIndexToMail[mailIndex] = account[j];
                    mailIndex++;
                }

                mapMailIndexToNameIndex[mapMailToIndex[account[j]]] = i;
            }
        }

        for (int i = 0; i < accounts.size(); i++) {
            const vector<string>& account = accounts[i];
            for (int j = 2; j < account.size(); j++) {
                merge(mapMailToIndex[account[j]], mapMailToIndex[account[1]]);
            }
        }

        for (const pair<int, int>& mailIndexToNameIndex : mapMailIndexToNameIndex) {
            int currentMailIndex = mailIndexToNameIndex.first, nameIndex = mailIndexToNameIndex.second;
            int parent = findParent(currentMailIndex);
            if (!mapDisjointSetIndexToAnswerIndex.count(parent)) {
                answer.push_back(vector<string>());
                answer[answerIndex].push_back(accounts[nameIndex][0]);
                answer[answerIndex].push_back(mapIndexToMail[currentMailIndex]);
                mapDisjointSetIndexToAnswerIndex[parent] = answerIndex++;
            } else {
                answer[mapDisjointSetIndexToAnswerIndex[parent]].push_back(mapIndexToMail[currentMailIndex]);
            }
        }

        for (vector<string>& oneAnswer : answer) {
            std::sort(oneAnswer.begin() + 1, oneAnswer.end());
        }
        return answer;
    }
};