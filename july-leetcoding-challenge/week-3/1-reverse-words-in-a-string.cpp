class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int pointer = 0;
        
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin()+pointer, s.begin()+i);
                pointer = i+1;
                while(i < s.size() && s[i] == ' ') i++;
                if (pointer != i) s.erase(s.begin()+pointer, s.begin()+i);
                i = pointer;
            }
        }
        
        reverse(s.begin()+pointer, s.end());
        
        int begin = 0, end = 0;
        while(begin < s.size() && s[begin] == ' ') begin++;
        
        if (begin == s.size()) return "";
        
        while(end < s.size() && s[s.size()-1-end] == ' ') end++;
        
        s.erase(s.begin(), s.begin()+begin);
        s.erase(s.end()-end, s.end());
        
        
        
        return s;
    }
};