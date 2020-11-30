class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
		    this->A = A;
    }
    
    int next(int n) {
		    int ans = -1;
		    while (n > 0 && ptr < A.size()) {
			      if (A[ptr] >= n) {
				        A[ptr] -= n;
                n = 0;
				        ans = A[ptr + 1];
            } else {
	            n -= A[ptr];
	            A[ptr] = 0;
            }

            if (A[ptr] == 0) ptr += 2;
        }
        return ans;
    }
private:
	  vector<int> A;
	  int ptr = 0;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */


