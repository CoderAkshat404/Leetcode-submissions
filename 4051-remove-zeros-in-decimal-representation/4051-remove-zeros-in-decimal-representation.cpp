class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n);
        string a="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                a+=s[i];
           }
        }
        return stoll(a);
    }
};