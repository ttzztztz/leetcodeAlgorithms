class Solution {
public:
    int minAddToMakeValid(string S) {
		int balance = 0;
		int ans = 0;
		const int n = S.size();

		for (int i = 0; i < n; i++) {
			if (S[i] == '(') {
				balance++;
            } else { // S[i] == ')'
                if (balance == 0) ans++;
                else balance--;
            }
        }
		return ans + balance;
    }
};


