class Cashier {
public:
    unordered_map<int, int> menu;
    int n, discount, id;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        const int N = products.size();
        
        for (int i = 0; i < N; i++) {
            menu[products[i]] = prices[i];
        }
        this->n = n;
        this->discount = discount;
        this->id = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        id++;
        double current = 0.0;
        
        const int N = product.size();
        for (int i = 0; i < N; i++) {
            current += menu[product[i]] * amount[i];
        }
        
        if (id == n) {
            current -= (discount * current) / 100.0;
            id = 0;
        }
        return current;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
