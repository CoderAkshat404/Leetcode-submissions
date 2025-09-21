class Solution {
public:
    int myAtoi(string s) {
        string p = "";
        int i = 0;

       
        while(i < s.length() && s[i] == ' ') i++;

       
        if(i < s.length() && (s[i] == '-' || s[i] == '+')){
            p += s[i];
            i++;
        }

        while(i < s.length() && (s[i] >= '0' && s[i] <= '9')){
            p += s[i];
            i++;
        }

        if(p == "" || p == "+" || p == "-") return 0; 
        int j=0;
        int x=p.length();
        while(p[j]=='0' || p[j]=='-'){
            j++;
            x--;
        }
        if(x>18){
            if(p[0]=='-'){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }

        long long val = stoll(p); 
        if(val > INT_MAX) return INT_MAX;
        if(val < INT_MIN) return INT_MIN;
        return (int)val;
    }
};
