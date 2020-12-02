class Solution {
 public:
	bool canIWin(int max_choose_integer, int desired_total) {
		if (desired_total == 0) return true;
        
        int max_choose = 0;
		for (int i = 1; i <= max_choose_integer; i++) max_choose += i;
		if (max_choose < desired_total) return false;

		this->memo_ = vector<int>((1 << max_choose_integer) + 1, -1);
		this->max_choose_integer_ = max_choose_integer, this->desired_total_ = desired_total;
		return Dfs(0) == 1;
};
 private:
	int max_choose_integer_, desired_total_;
	vector<int> memo_;
	
	int Dfs(int state) {
		int& val = memo_[state];
		if (val != -1) return val;
		int ans = 0, current = 0;
		for (int i = 0; i < max_choose_integer_; i++) {
			if (state & (1 << i)) current += (i + 1);
        }

		for (int i = 0; i < max_choose_integer_; i++) {
			if (state & (1 << i)) continue;
			if (current + i + 1 >= desired_total_) {
				ans = 1;
				break;
            }
			if (!Dfs(state | (1 << i))) {
				ans = 1;
				break;
			}
        }
		return val = ans;
	}
};


