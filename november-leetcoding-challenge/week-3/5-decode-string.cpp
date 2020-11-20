class Solution {
public:
    string copyString(string s, int quant) {
        string result = "";
        for (int i=0; i<quant; i++) {
            result += s;
        }
        
        return result;
    }
    
    int nextIdx(string s, int idx) {
        int open = 1;
        while (open) {
            if (s[idx] == '[') open++;
            if (s[idx] == ']') open--;
            idx++;
        };

        return idx-1;
    }
    string decodeString(string s) {
        string result = "";
        for (int i=0; i<s.size(); i++) {
            if (isdigit(s[i])) {
                int quant = 0;
                while(isdigit(s[i])) {
                    quant *= 10;
                    quant += s[i] - '0';
                    i++;
                }
                
                if (s[i] == '[') i++;
                else return "ERROR!";
                
                int j = nextIdx(s, i);

                string temp = decodeString(s.substr(i, j-i));
                result += copyString(temp, quant);
                i = j;
            } else {
                result += s[i];   
            }
        }
        
        return result;
    }
};