class Solution {
public:
    int calc(long long x) {
        int answer = 0;
        while (x != 1) {
            if (x % 2 == 1) x = 3 * x + 1;
            else x /= 2;

            answer++;
        }
        return answer;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> allNumber;
        for (int i = lo; i <= hi; i++) {
            allNumber.emplace_back(calc(i), i);
        }
        sort(allNumber.begin(), allNumber.end(), [&](const auto& $1, const auto& $2)->bool {
            if ($1.first == $2.first) return $1.second < $2.second;
            return $1.first < $2.first;
        });
        return allNumber[k - 1].second;
    }
};
