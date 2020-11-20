class Solution {
public:
    int intlog(double base, double x) {
        return ceil(log(x) / log(base));
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest/minutesToDie + 1;
        return intlog(t, buckets);
    }
};