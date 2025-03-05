class ProductOfNumbers {
public:
    ProductOfNumbers() {
        product = { 1 };
    }
    
    void add(int num) {
        if (num == 0) {
            product = { 1 };
            return;
        }

        product.push_back(product.back() * num);
    }
    
    int getProduct(int k) {
        const int n = product.size();
        if (n - k - 1 < 0) return 0;

        return product[n - 1] / product[n - k - 1];
    }
private:
    typedef long long ll;
    vector<ll> product;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */