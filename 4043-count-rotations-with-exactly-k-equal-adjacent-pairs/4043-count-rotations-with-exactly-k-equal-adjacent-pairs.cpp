class Solution {
public:
    int countRotations(string s, int k) {
        int ans=0;
        int x=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                ans++;
            }
        }
        if(ans==k){
           x++; 
        }
        
        for(int i=0;i<s.length()-1;i++){
            string temp="";
            for(int j=i+1;j<s.length();j++){
                temp+=s[j];
            }
            for(int j=0;j<=i;j++){
                temp+=s[j];
            }
            int ans=0;
            for(int j=0;j<temp.length()-1;j++){
                if(temp[j]==temp[j+1]){
                ans++;
            }
            
            }
            if(ans==k){
                    x++;
            }
        }
        return x;
        
    }
};