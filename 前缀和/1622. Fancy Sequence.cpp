class Fancy {
public:
    Fancy() {
        f = {0};
        g = {1};
    }
    
    void append(int val) {
        data.push_back(val);
        f.push_back(f.back());
        g.push_back(g.back());
    }
    
    void addAll(int inc) {
        f.back() = (f.back() + inc) % mod;
    }
    
    void multAll(int m) {
        f.back() = (f.back() * m) % mod;
        g.back() = (g.back() * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= data.size()) return -1;

        ll d = g.back() * inv(g[idx]) % mod;
        return ((d * data[idx] + f.back() - f[idx] * d) % mod + mod) % mod;
    }
private:
    const int mod = 1e9+7;
    typedef long long ll;
    vector<ll> f, g, data;
    
    ll inv(ll a) {
        return fastPow(a, mod - 2);
    }
    ll fastPow(ll a, int b) {
        ll ans = 1, pow = a;
        
        while (b) {
            if (b & 1) {
                ans = (ans * pow) % mod;
            }
            
            pow = (pow * pow) % mod;
            b >>= 1;
        }
        
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
