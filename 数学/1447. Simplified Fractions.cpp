class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        unordered_set<string> answer;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                answer.insert(handle(j, i));
            }
        }
        return vector<string>(answer.begin(), answer.end());
    }
private:
    string handle(int j, int i) {
        for (int k = min(j, i); k >= 1; k--) {
            if (j % k == 0 && i % k == 0) {
                j /= k;
                i /= k;
            }
        }
        return to_string(j) + "/" + to_string(i);
    }
};
