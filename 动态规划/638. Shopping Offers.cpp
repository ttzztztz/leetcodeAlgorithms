class Solution {
public:
    map<vector<int>, int> dp;
    bool isFinal(const vector<int>& needs) {
        for (int need : needs) {
            if (need != 0) {
                return false;
            }
        }
        return true;
    }
    int currentPrice(const vector<int>& price, const vector<int>& needs) {
        int answer = 0;
        for (int i = 0; i < needs.size(); i++) {
            answer += price[i] * needs[i];
        }
        return answer;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (isFinal(needs)) {
            return 0;
        }
        if (dp.count(needs)) {
            return dp[needs];
        }

        int answer = currentPrice(price, needs);
        for (const vector<int>& spec : special) {
            bool isValid = true;
            for (int j = 0; j < spec.size() - 1; j++) {
                if (needs[j] - spec[j] < 0) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) {
                continue;
            }

            for (int j = 0; j < spec.size() - 1; j++) {
                needs[j] -= spec[j];
            }
            answer = min(answer, *spec.rbegin() + shoppingOffers(price, special, needs));
            for (int j = 0; j < spec.size() - 1; j++) {
                needs[j] += spec[j];
            }
        }

        return dp[needs] = answer;
    }
};