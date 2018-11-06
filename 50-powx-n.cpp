class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == INT_MIN) {
            return 1 / (myPow(x, INT_MAX) * x);
        }
        if (n < 0) {
            return 1 / myPow(x, -n);
        }
        
        double power = myPow(x, n / 2);
        power = power * power;
        if (n % 2 == 1) {
            power *= x;
        }
        
        return power;
    }
};

