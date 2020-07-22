class Solution {
public:
    double pow(double x, long long int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        if (x < 0.00000 && x > -0.00000) return 0.0;
        
        double half = myPow(x,n/2);
        double result = half * half;
        
        if (n & 1) result *= x;
        
        return result;
    }
    double myPow(double x, int n) {
        long long int k = n;
        if (x == 1.0) return 1.0;
        if (n > 0) return pow(x, k);
        return 1.0 / pow(x, -k);
    }
};