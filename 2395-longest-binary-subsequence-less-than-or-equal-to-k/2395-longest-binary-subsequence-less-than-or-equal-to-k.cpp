class Solution {
public:
    int longestSubsequence(string s, int k) {
        // unordered_map<int,bool> m;
        // for(int i=0;i<64;i++){
        //     int b=(k>>i)&1;
        //     if(b==1){
        //         m[i]=1;
        //     }
        // }
        // int cnt=0;
        int x=0;
        int ans=0;
        int cnt=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                if(x+pow(2,s.length()-1-i)<=k){
                    ans++;
                    x+=pow(2,s.length()-1-i);
                }

            }
            else{
                ans++;
            }
            
        }
        return ans;

        
    }
};