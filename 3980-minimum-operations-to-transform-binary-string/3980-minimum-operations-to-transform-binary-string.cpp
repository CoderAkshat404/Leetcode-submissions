class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='1' && s2[i]=='0' && i==n-1){
                if(i-1>=0){
                    ans+=2;
                }
                else{
                    return -1;
                }
            }
            else if(s1[i]=='0' && s2[i]=='1'){
                s1[i]='1';
                ans++;
            }
            else if(s1[i]=='1' && s2[i]=='0' && i+1<n && s1[i+1]=='1'){
                ans++;
                s1[i]='0';
                s1[i+1]='0';
            }
            else if(s1[i]=='1' && s2[i]=='0' && i+1<n && s1[i+1]=='0'){
                ans++;
                s1[i]='0';
                s1[i+1]='0';
                ans++;
            }

           
        }
        return ans;
        
    }
};