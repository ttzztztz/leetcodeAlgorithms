class Solution {
public:
  int copyBooks(vector<int> &pages, int k) {
      if (pages.empty()) return 0;
      int l = *max_element(pages.begin(), pages.end()), r = accumulate(pages.begin(), pages.end(), 0);
      while (l <= r) {
        const int mid = (l + r) / 2;
        const int val = solve(pages, mid);	
        if (val > k) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      return l;
  }
private:
	int solve(vector<int> &pages, int max_minutes) {
		int need_people = 0, cur = 0;
		for (int i = 0; i < pages.size(); i++) {
			if (cur + pages[i] <= max_minutes) {
        cur += pages[i];
			} else {
				cur = pages[i], need_people++;
      }
    }

    if (cur > 0) need_people++;
	return need_people;
  }
};
