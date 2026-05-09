class Solution {
public:
    bool validDigit(int n, int x) {
        string s=to_string(n);
        if(s.find(char(x+'0'))!=string::npos && s[0]!=char('0'+x)) return true;
        return false;
        
    }
};