class Solution {
public:
    int minLength(string s) {
        while(s.find("AB") != string::npos || s.find("CD") != string::npos) {
            if(s.find("AB") != string::npos) {
                int k = s.find("AB");
                s.erase(k, 2);
            }
            else if(s.find("CD") != string::npos) {
                int k = s.find("CD");
                s.erase(k, 2);
            }
        }
        return s.length();
    }
};
