class Solution {
public:
    /**
     * @param cards: A list of cards.
     * @return: A list of feasible solution.
     */
    vector<int> getTheNumber(vector<int> &cards) {
        // write your code here
        card = vector<int>(10, 0);
        for (int i : cards) card[i]++;
        
        vector<int> ans;
        const vector<int> init_card = card;
        for (int i = 1; i <= 9; i++) {
            card = init_card;
            
            if (card[i] >= 4) continue;
            card[i]++;
            if (dfs(14)) {
                ans.push_back(i);
            }
        }
        
        if (ans.empty()) return {0};
        return ans;
    }
private:
    vector<int> card;
    bool dfs(int remain) {
        if (remain == 2) {
            vector<int> one_card;
            for (int i = 1; i <= 9; i++) {
                if (card[i] > 0) {
                    one_card.push_back(i);
                }
            }
            return one_card.size() == 1;
        }

        for (int i = 1; i <= 9; i++) {
            if (card[i] >= 3) {
                card[i] -= 3;
                if (dfs(remain - 3)) return true;
                card[i] += 3;
            }

            if (i + 2 <= 9 && card[i] > 0 && card[i + 1] > 0 && card[i + 2] > 0) {
                card[i]--;
                card[i + 1]--;
                card[i + 2]--;
                if (dfs(remain - 3)) return true;
                card[i]++;
                card[i + 1]++;
                card[i + 2]++;
            }
        }
        return false;
    }
};
