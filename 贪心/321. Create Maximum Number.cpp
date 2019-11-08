class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int N = nums1.size(), M = nums2.size();

        vector<int> answer;
        for (int i = 0; i <= k; i++) {
            if (i > N || k - i > M) {
                continue;
            }
            vector<int> temp1 = solve(nums1, i);
            vector<int> temp2 = solve(nums2, k - i);

            vector<int> oneAnswer = merge(temp1, temp2);
            answer = max(answer, oneAnswer);
        }
        return answer;
    }

    vector<int> solve(const vector<int>& nums, int k) {
        vector<int> answer;
        if (k == 0) {
            return answer;
        }
        int willPop = nums.size() - k;

        for (int i = 0; i < nums.size(); i++) {
            const int num = nums[i];

            while (answer.size() > 0 && answer.back() < num && willPop > 0) {
                answer.pop_back();
                willPop--;
            }

            answer.push_back(num);
        }

        answer.resize(k);
        return answer;
    }

    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> answer;
        const int nums1_N = nums1.size(), nums2_M = nums2.size();

        auto it1 = nums1.begin(), it2 = nums2.begin();
        auto end1 = nums1.end(), end2 = nums2.end();

        while (it1 != end1 || it2 != end2) {
            if (lexicographical_compare(it1, end1, it2, end2)) {
                answer.push_back(*it2);
                it2++;
            } else {
                answer.push_back(*it1);
                it1++;
            }
        }

        return answer;
    }
};