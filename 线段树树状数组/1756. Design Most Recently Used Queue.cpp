class MRUQueue {
public:
    MRUQueue(int n) {
        memset(data, 0, sizeof data);
        for (int i = 1; i <= n; i++) {
            val[i] = i;
            inc(i, 1);
        }
        last = n;
    }
    
    int fetch(int k) {
        int l = 1, r = last;
        while (l <= r) {
            const int mid = (l + r) / 2;
            if (query(mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        const int ans = val[l];
        val.erase(l);
        inc(l, -1);
        last++;
        inc(last, 1);
        val[last] = ans;
        return ans;
    }
private:
    unordered_map<int, int> val;
    int data[4005];
    int last;
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int u) {
        int ans = 0;
        while (u) {
            ans += data[u];
            u -= lowbit(u);
        }
        return ans;
    }
    void inc(int u, int v) {
        while (u && u <= 4000) {
            data[u] += v;
            u += lowbit(u);
        }
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
