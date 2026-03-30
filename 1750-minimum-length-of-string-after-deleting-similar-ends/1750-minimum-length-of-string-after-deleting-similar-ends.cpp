class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                char temp=s[i];
                int previ=i;
                while(s[i]==temp && i<j){
                    i++;
                }
                while(s[j]==temp && j>previ){
                    j--;
                }
            }
            else{
                break;
            }
        }
        if(i>j) return 0;
        if(i==j) return 1;
        return j-i+1;
        
    }
};