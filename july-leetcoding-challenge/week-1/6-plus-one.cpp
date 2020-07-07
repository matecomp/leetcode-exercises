class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        int carry = 0;
        for (int i=digits.size()-1; i>=0; i--) {
            int value = digits[i] + carry;
            carry = value/10;
            digits[i] = value%10;
        }
        
        if (carry) digits.insert(digits.begin(), carry);
        
        return digits;
    }
};