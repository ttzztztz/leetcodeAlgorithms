class FooBar {
private:
    int n;
    mutex mu;
    condition_variable cv;
    bool ready = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(mu);
            cv.wait(lk, [&]() -> bool{
                return ready == false;
            });
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ready = true;

            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(mu);
            cv.wait(lk, [&]() -> bool{
                return ready == true;
            });
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            ready = false;
            lk.unlock();
            cv.notify_one();
        }
    }
};
