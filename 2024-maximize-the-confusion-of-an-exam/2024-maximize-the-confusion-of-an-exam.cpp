class Solution {
public:
    int solve(char c,string s, int k){
        int l=0;
        int r=-1;
        int n=s.length();
        int maxi=-1;
        while(l<n){
            while(r+1<n && (s[r+1]==c || k>0)){
                r++;
                if(s[r]!=c) k--;
            }
            maxi=max(maxi,r-l+1);
            if(l>r){
                l++;
                r=l-1;
            }
            else{
                if(s[l]!=c) k++;
                l++;
            }
        }
        return maxi;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0;
        ans=max(ans,solve('T',answerKey,k));
         ans=max(ans,solve('F',answerKey,k));
         return ans;
        
    }
};