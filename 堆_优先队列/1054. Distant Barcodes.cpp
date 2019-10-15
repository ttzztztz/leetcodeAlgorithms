class Number {
public:
    int number, count;
    Number() : number(0), count(0) {};
    Number(int n, int c) : number(n), count(c) {};
    bool operator< (const Number& $2) const {
        return this->count < $2.count;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> answer;
        int statics[10001];
        std::memset(statics, 0, sizeof(statics));

        int maxIndex = -1, maxCount = 0;
        for (int i = 0; i < barcodes.size(); i++) {
            const int number = barcodes[i];
            statics[number]++;

            if (statics[number] > maxCount) {
                maxCount = statics[number];
                maxIndex = i;
            }
        }
        answer.resize(barcodes.size());
        priority_queue<Number> queue;
        for (int i = 0; i < 10001; i++) {
            if (statics[i] > 0) {
                queue.emplace(i, statics[i]);
            }
        }

        int currentIndex = 0;
        while (!queue.empty()) {
            Number number = queue.top();
            queue.pop();

            for (int i = 0; i < number.count; i++) {
                answer[currentIndex] = number.number;
                currentIndex += 2;

                if (currentIndex >= barcodes.size()) {
                    currentIndex = 1;
                }
            }
        }

        return answer;
    }
};