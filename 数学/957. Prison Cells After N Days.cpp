class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int state = 0;
        for (int i = 0; i < cells.size(); i++) {
            if (cells[i] == 1) state |= (1 << i);
        }
        
        unordered_map<int, int> memo;
        while (N) {
            if (memo.count(state)) {
                N %= memo[state] - N;
            }
            
            memo[state] = N;
            if (N > 0) {
                N--;
                state = nxtState(state);
            }
        }
        
        vector<int> answer;
        for (int i = 0; i < cells.size(); i++) {
            if (state & (1 << i)) answer.push_back(1);
            else answer.push_back(0);
        }
        return answer;
    }
private:
    int nxtState(int state) {
        int nextState = 0;
        for (int i = 1; i <= 6; i++) {
            const bool b1 = (state & (1 << (i - 1))) && (state & (1 << (i + 1)));
            const bool b2 = !(state & (1 << (i - 1))) && !(state & (1 << (i + 1)));
            
            if (b1 || b2) {
                nextState |= 1 << i;
            }
        }
        
        // cout << state << ", " << nextState << endl;
        return nextState;
    }
};
