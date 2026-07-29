class Solution {
public:
    string smallestPalindrome(string s) {
       vector<int> freq(26,0);
       for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
       }
       int n=s.length();
       string ans="";
       for(int i=0;i<n;i++){
        ans+='#';
       }
       char c;
       if(n&1){
        
        for(int i=0;i<freq.size();i++){
            if(freq[i]&1){
                c=i+'a';
            }
        }
       }
       int i=0;
       int k=0;
       while(i<26){
            if(freq[i]==0 || freq[i]==1){
                i++;
                continue;
            }
            else{
                ans[k]=i+'a';
                ans[n-k-1]=i+'a';
                freq[i]=freq[i]-2;
                k++;
            }
       }
       if(n&1){
        ans[n/2]=c;
       }
       return ans;
        
    }
};