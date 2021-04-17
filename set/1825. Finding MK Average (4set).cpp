class MKAverage {
public:
    MKAverage(int m, int k) {
        this->m = m, this->k = k;
    }
    
    void addElement(int num) {
        data.push_back(num);
        
        mx_backup.insert(num);
        mi_backup.insert(num);
        
        sum += num;
        if (data.size() > m) {
            const int t = data[data.size() - m - 1];
            sum -= t;
            
            if (mx_backup.find(t) != mx_backup.end()) {
                mx_backup.erase(mx_backup.find(t));
            } else if (mx_primary.find(t) != mx_primary.end()) {
                sum_mx -= t;
                mx_primary.erase(mx_primary.find(t));
            }
            
            if (mi_backup.find(t) != mi_backup.end()) {
                mi_backup.erase(mi_backup.find(t));
            } else if (mi_primary.find(t) != mi_primary.end()) {
                sum_mi -= t;
                mi_primary.erase(mi_primary.find(t));
            }
        }
        
        while (!mx_backup.empty() && mx_primary.size() < k) {
            const int t = *mx_backup.rbegin();
            sum_mx += t;
            mx_primary.insert(t);
            mx_backup.erase(mx_backup.find(t));
        }
        while (!mi_backup.empty() && mi_primary.size() < k) {
            const int t = *mi_backup.begin();
            sum_mi += t;
            mi_primary.insert(t);
            mi_backup.erase(mi_backup.find(t));
        }

        while (!mx_backup.empty() && !mx_primary.empty() && *mx_primary.begin() < *mx_backup.rbegin()) {
            const int a = *mx_primary.begin();
            const int b = *mx_backup.rbegin();
            
            sum_mx -= a;
            sum_mx += b;
            
            mx_primary.erase(mx_primary.find(a));
            mx_backup.erase(mx_backup.find(b));
            
            mx_primary.insert(b);
            mx_backup.insert(a);
        }
        while (!mi_backup.empty() && !mi_primary.empty() && *mi_primary.rbegin() > *mi_backup.begin()) {
            const int a = *mi_primary.rbegin();
            const int b = *mi_backup.begin();
            
            sum_mi -= a;
            sum_mi += b;
            
            mi_primary.erase(mi_primary.find(a));
            mi_backup.erase(mi_backup.find(b));
            
            mi_primary.insert(b);
            mi_backup.insert(a);
        }
        
        // cout << sum << "," << sum_mi << "," << sum_mx << endl;
    }
    
    int calculateMKAverage() {
        if (data.size() < m) return -1;
        else {
            // cout << sum << "," << sum_mi << "," << sum_mx << endl;
            ll a = (sum - sum_mi - sum_mx);
            ll b = (m - 2 * k);
            return a / b;
        }
    }
private:
    int m, k;
    vector<int> data;
    multiset<int> mx_primary, mx_backup, mi_primary, mi_backup;
    typedef long long ll;
    ll sum_mx = 0, sum_mi = 0, sum = 0;
    
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */