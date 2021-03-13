class pqueue {
public:
    void push(int u) {
        data.push_back(u);
        adjust_up(data.size() - 1);
    }
    void pop() {
        swap(data[0], data[data.size() - 1]);
        data.pop_back();
        if (!data.empty()) {
            adjust_down(0);
        }
    }
    int top() {
        return data[0];
    }
    size_t size() {
        return data.size();
    }
private:
    vector<int> data;
    void adjust_up(int u) {
        while (u > 0) {
            const int parent = (u - 1) / 2;
            
            if (data[u] < data[parent]) {
                swap(data[u], data[parent]);
                u = parent;
            } else {
                break;
            }
        }
    }
    void adjust_down(int u) {
        const int n = data.size();
        while (u < n) {
            int next = u;
            const int l = u * 2 + 1, r = u * 2 + 2;
            if (l < n && data[next] > data[l]) next = l;
            if (r < n && data[next] > data[r]) next = r;
            
            if (next == u) break;
            swap(data[next], data[u]);
            u = next;
        }
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        pqueue heap;
        for (int i : nums) {
            if (heap.size() < k) {
                heap.push(i);
            } else {
                if (heap.top() < i) {
                    heap.pop();
                    heap.push(i);
                }
            }
        }
        return heap.top();
    }
};