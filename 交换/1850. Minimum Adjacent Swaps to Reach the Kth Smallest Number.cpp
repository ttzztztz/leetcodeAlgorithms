class BIT {
public:
    int data[1005];
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int x) {
        x++;
        int ans = 0;
        while (x) {
            ans += data[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void inc(int u, int v) {
        u++;
        while (u && u <= 1002) {
            data[u] += v;
            u += lowbit(u);
        }
    } 
    BIT() {
        memset(data, 0, sizeof data);
    }
};

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string last = num;
        for (int i = 0; i < k; i++) next_permutation(last.begin(), last.end());
        
        int ans = 0;
        vector<set<int>> index(10);
        const int n = num.size();
        
        for (int i = 0; i < n; i++) {
            index[num[i] - '0'].insert(i);
        }
        
        for (int i = 0; i < n; i++) {
            auto b = index[last[i] - '0'].begin();
            // cout << i << "," << *b << "," << bit.query(i) << endl;
            ans += *b - bit.query(*b);
            bit.inc(*b, 1);
            index[last[i] - '0'].erase(b);
        }
        // cout << endl;
        return ans;
    }
private:
    BIT bit;
};