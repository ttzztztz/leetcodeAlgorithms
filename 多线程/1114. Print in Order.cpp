class Foo {
public:
    mutex mu;
    bool b1 = false, b2 = false, b3 = false;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        b1 = true;
    }

    void second(function<void()> printSecond) {
        while (!b1) {}
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        b2 = true;
    }

    void third(function<void()> printThird) {
        while (!b1 || !b2) {}
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
