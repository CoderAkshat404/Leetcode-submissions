class Solution {
public:
    int minOperations(string s) {
        int small=-1;
        char mini='z';
        int large=-1;
        char maxi='a';
        for(int i=0;i<s.length();i++){
            if(s[i]<mini){
                mini=s[i];
                small=i;
            }
            if(s[i]>=maxi){
                maxi=s[i];
                large=i;
            }
        }
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s){
            return 0;
        }
        int n=s.length();
        if(n==1){
            return 0;
        }
        if(n==2 && small==n-1){
            return -1;
        }
        
        if(small==n-1 && large==0){
            return 3;
        }
        if(small==0 || large==n-1){
            return 1;
        }
        return 2;
        
    }
};