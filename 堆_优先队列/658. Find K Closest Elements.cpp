class Element {
public:
    int abs, number;
    Element() : abs(0), number(0) {};
    Element(int a, int n) : abs(a), number(n) {};
    bool operator<(const Element& e) const {
        if (this->abs == e.abs) {
            return this->number < e.number;
        } else {
            return this->abs < e.abs;
        }
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<Element> queue;
        for (int number : arr) {
            queue.emplace(abs(number - x), number);

            while (queue.size() > k) {
                queue.pop();
            }
        }

        vector<int> answer;
        for (int i = 0; i < k; i++) {
            Element e = queue.top();
            queue.pop();
            answer.push_back(e.number);
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};