class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s=to_string(num);
        if(s[s.length()-1]=='0' && s.length()>1){
            return false;
        }
        else{
            return true;
        }
        
    }
};