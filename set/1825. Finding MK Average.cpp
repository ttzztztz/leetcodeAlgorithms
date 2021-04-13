class MKAverage {
public:
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
    }
    
    void addElement(int num) {
        data.push_back(num);
        sum += num;
        candidate.insert(num);
        
        if (data.size() > m) {
            const int t = data[data.size() - m - 1];
            sum -= t;
            if (mxs.count(t)) {
                sum_mx -= t;
                mxs.erase(mxs.find(t));
            } else if (candidate.count(t)) {
                candidate.erase(candidate.find(t));
            } else if (mis.count(t)) {
                sum_mi -= t;
                mis.erase(mis.find(t));
            }
        }
        
        if (data.size() >= m) {
            while (!mis.empty() && !candidate.empty() && *mis.rbegin() > *candidate.begin()) {
                const int a = *mis.rbegin();
                const int b = *candidate.begin();
                
                sum_mi += b - a;
                
                mis.insert(b), mis.erase(mis.find(a));
                candidate.insert(a), candidate.erase(candidate.find(b));
            }
            
            while (!mxs.empty() && !candidate.empty() && *mxs.begin() < *candidate.rbegin()) {
                const int a = *mxs.begin();
                const int b = *candidate.rbegin();
                
                sum_mx += b - a;
                
                mxs.insert(b), mxs.erase(mxs.find(a));
                candidate.insert(a), candidate.erase(candidate.find(b));
            }
            
            while (mis.size() < k) {
                const int t = *candidate.begin();
                sum_mi += t;
                candidate.erase(candidate.find(t)), mis.insert(t);
            }
            
            while (mxs.size() < k) {
                const int t = *candidate.rbegin();
                sum_mx += t;
                candidate.erase(candidate.find(t)), mxs.insert(t);
            }
        }
    }
    
    int calculateMKAverage() {
        if (data.size() < m) return -1;

        ll a = sum - sum_mi - sum_mx;
        ll b = m - 2 * k;
        return a / b;
    }
private:
    int m, k;
    vector<int> data;
    multiset<int> mxs, mis, candidate;
    typedef long long ll;
    ll sum_mx = 0, sum_mi = 0, sum = 0;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */