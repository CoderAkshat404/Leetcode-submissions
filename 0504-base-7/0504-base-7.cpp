class Solution {
public:
    string convertToBase7(int n) {
        int y=n;
        string s="";
        while(n!=0){
            int x=n%7;
            s+=to_string(abs(x));
            n=n/7;
        }
        reverse(s.begin(),s.end());
        if(y<0){
            return '-'+s;

        }
        if(y==0){
            return "0";
        }
        else{
            return s;
        }
        
        
    }
};