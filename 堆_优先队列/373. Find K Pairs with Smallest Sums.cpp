class Pair {
public:
    int u, v;
    Pair() : u(0), v(0) {};
    Pair(int _u, int _v) : u(_u), v(_v) {};
    int sum() const {
        return this->u + this->v;
    }
    bool operator<(const Pair& $2) const {
        return this->sum() < $2.sum();
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Pair> queue;
        vector<vector<int>> answer;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (queue.size() > k && nums1[i] + nums2[j] > queue.top().sum()) {
                    break;
                }

                queue.push(Pair(nums1[i], nums2[j]));
                if (queue.size() > k) {
                    queue.pop();
                }
            }
        }

        while (!queue.empty()) {
            const Pair topElement = queue.top();
            vector<int> oneAnswer = {topElement.u, topElement.v};
            answer.push_back(oneAnswer);
            queue.pop();
        }
        std::reverse(answer.begin(), answer.end());

        return answer;
    }
};