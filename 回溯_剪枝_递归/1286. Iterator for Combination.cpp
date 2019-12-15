class CombinationIterator {
public:
    string str;
    vector<int> state;
    vector<int> finalState;
    bool begin;
    int combinationLength;
    CombinationIterator(string characters, int combinationLength) : str(characters), combinationLength(combinationLength) {
        const int N = characters.size();
        begin = true;
        for (int i = 0; i < combinationLength; i++) {
            state.push_back(i);
            finalState.push_back(i);
        }
    }

    int dfs(int u, int i) {
        if (u < 0) {
            return -1;
        }

        state[u]++;
        if (state[u] + i >= str.size()) {
            state[u] = dfs(u - 1, i + 1) + 1;
        }
        return state[u];
    }

    string next() {
        begin = false;

        string answer;
        // get
        for (int i : state) {
            answer += str[i];
        }
        // tranform
        dfs(state.size() - 1, 0);
        return answer;
    }

    bool hasNext() {
        return begin || state != finalState;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */