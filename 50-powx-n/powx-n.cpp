class Solution {
public:
    double myPow(double x, int n) {
         double ans = 1.0;
    long long N = n; // overflow handle karne ke liye
    if(N < 0) {
        x = 1 / x;
        N = -N;
    }
    
    while(N > 0) {
        if(N % 2 == 1)
            ans = ans * x;
        x = x * x;
        N = N / 2;
    }
    
    return ans;
    }
};