class Solution {
public:
    
    string ans="";
    void rec(int n,int k,char prev){
        if(n==0) return ;
        if(prev=='x'){
        if(k<=(1<<(n-1))){
            ans+='a';
            rec(n-1,k,'a');
        }
        else if(k<=(1<<n)){
            ans+='b';
            rec(n-1,k-(1<<(n-1)),'b');
        }
        else{
            ans+='c';
            rec(n-1,k-((1<<n)),'c');
        }
        }
        else if(prev=='a'){
            if(k<=(1<<(n-1))){
            ans+='b';
            rec(n-1,k,'b');
            }
            else{
                ans+='c';
                rec(n-1,k-(1<<(n-1)),'c');

            }

        }
        else if(prev=='b'){
            if(k<=(1<<(n-1))){
            ans+='a';
            rec(n-1,k,'a');
            }
            else{
                ans+='c';
                rec(n-1,k-(1<<(n-1)),'c');

            }

        }
        else{
            if(k<=(1<<(n-1))){
            ans+='a';
            rec(n-1,k,'a');
            }
            else{
                ans+='b';
                rec(n-1,k-(1<<(n-1)),'b');

            }

        }
    }
    string getHappyString(int n, int k) {
        if(k>(3*(1<<(n-1)))){
            return "";
        }
        else{
            rec(n,k,'x');
        }
        return ans;
        
    }
};