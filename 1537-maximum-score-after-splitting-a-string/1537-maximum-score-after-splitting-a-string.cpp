class Solution {
public:
    int maxScore(string s) {
        int maxscore=INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            int sc1=0;
            int sc2=0;
            for(int j=0;j<=i;j++){
                if(s[j]=='0'){
                    sc1++;
                }
            }
            for(int j=i+1;j<s.length();j++){
                if(s[j]=='1'){
                    sc2++;
                }
            }
            int ans=sc1+sc2;
            maxscore=max(maxscore,ans);
        }
     return maxscore;   
    }
};