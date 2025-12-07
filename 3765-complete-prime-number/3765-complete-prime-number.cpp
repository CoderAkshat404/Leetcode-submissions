class Solution {
public:
    bool check(int n){
        if(n==1){
            return false;
        }
        bool ans=true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0 && i!=n){
                ans=false;
                break;
            }
        }
        return ans;
    }
    bool completePrime(int num) {
        string s=to_string(num);
        string c="";
        
        for(auto i:s){
            c+=i;
            int x=stoi(c);
            
            if(!check(x)){
                return false;
            }
        }
        c="";
        reverse(s.begin(),s.end());
        for(auto i:s){
            c+=i;
            reverse(c.begin(),c.end());
            int x=stoi(c);
            
            if(!check(x)){
                return false;
            }
            reverse(c.begin(),c.end());
        }
        return true;


        
    }
};