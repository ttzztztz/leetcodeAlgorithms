class Number {
public:
    int count, number;
    Number() : count(0), number(0) {};
    Number(int c, int n) : count(c), number(n) {};
    bool operator<(const Number& $2) const {
        return this->count > $2.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> answer;
        unordered_map<int, int> map;
        for (int number : nums) {
            if (!map.count(number)) {
                map[number] = 1;
            } else {
                map[number]++;
            }
        }

        priority_queue<Number, vector<Number>, less<>> queue;
        for (const pair<int, int>& kv : map) {
            queue.push(Number(kv.second, kv.first));
            if (queue.size() > k) {
                queue.pop();
            }
        }

        while (!queue.empty()) {
            answer.push_back(queue.top().number);
            queue.pop();
        }

        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};