class Solution {
public:
    int minimumRecolors(string s, int k) {
        int wc=0;
        int bc=0;
        int mini=INT_MAX;
        for(int i=0;i<k;i++){
            if(s[i]=='W'){
                wc++;
            }
            else{
                bc++;
            }
        }
        mini=min(mini,wc);
        int i=0;
        int j=k-1;
        while(j+1<s.length()){
            if(s[j+1]=='W'){
                wc++;
            }
            else{
                bc++;
            }
            if(s[i]=='B'){
                bc--;
            }
            else{
                wc--;
            }
            mini=min(mini,wc);
            i++;
            j++;
        }
        return mini;        
    }
};