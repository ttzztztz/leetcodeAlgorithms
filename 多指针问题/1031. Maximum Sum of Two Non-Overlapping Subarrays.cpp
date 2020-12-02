class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        this->n = A.size(), this->M = M;
		for (int i : A) pref.push_back(pref.back() + i);
		
		for (int l = 0, r = L - 1; r < n; l++, r++) {
			const int sum1 = pref[r + 1] - pref[l];
			solve(sum1, l, r);
        }

		return ans;
    }
private:
	vector<int> pref = {0};
	int ans = 0, n;
	int M;

	void solve(int sum1, int l1, int r1) {
		for (int l = 0, r = M - 1; r < n; l++, r++) {
			if (max(l1, l) <= min(r1, r)) continue;
			ans = max(ans, sum1 + pref[r + 1] - pref[l]);
		}
    }
};

