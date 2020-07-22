class Solution {
public:
    string addBinary(string a, string b) {
        int size = max(a.size(), b.size());
        string c = "";
        
        int carry = 0;
        for (int i=0; i<size; i++) {
            int a_idx = a.size() - (i+1);
            int b_idx = b.size() - (i+1);
            
            int a_val = 0, b_val = 0;
            
            if (a_idx >= 0 && a[a_idx] == '1') a_val = 1;
            if (b_idx >= 0 && b[b_idx] == '1') b_val = 1;
            
            int c_val = a_val ^ b_val ^ carry;
            
            if (carry) carry = a_val || b_val;
            else carry = a_val & b_val;

            if (c_val) c += '1';
            else c += '0';
        }
        
        if (carry) c += '1';
        
        reverse(c.begin(), c.end());
        return c;
    }
};