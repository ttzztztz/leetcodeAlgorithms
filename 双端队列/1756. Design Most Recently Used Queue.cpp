class MRUQueue {
public:
    MRUQueue(int n) {
        for (int i = 1; i <= n; i++) {
            q.push_back(i);
        }
    }
    
    int fetch(int k) {
        const int ans = q[k - 1];
        q.erase(q.begin() + k - 1);
        q.push_back(ans);
        return ans;
    }
private:
    deque<int> q;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
