class Solution {
public:
    long long int count_stars(long long int k) {
        return (1+k)*k/2;
    }

    int arrangeCoins(int n) {
        int left = 0;
        int right = n;
        
        if (n == 1) return 1;
        
        while(left+1 < right) {
            int middle = (left+right)/2;
            long long int stars = count_stars(middle);
            
            if (stars < n) left = middle;
            if (stars > n) right = middle;
            if (stars == n) return middle;
        }
        return left;
    }
};