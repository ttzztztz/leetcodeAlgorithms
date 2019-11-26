class Solution {
public:
    int N;
    bool check(const vector<int>& weights, int capacity, int D) {
        int sum = 0, answer = 0;

        for (int i = 0; i < N; i++) {
            if (sum + weights[i] > capacity) {
                answer++;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }

        if (sum > 0) {
            answer++;
        }
        return answer > D;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        N = weights.size();
        int sum = 0, minWeight = 0;
        for (int weight : weights) {
            sum += weight;
            minWeight = max(minWeight, weight);
        }

        int left = minWeight, right = sum;
        while (left <= right) {
            const int middle = (left + right) >> 1;

            if (check(weights, middle, D)) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return left;
    }
};