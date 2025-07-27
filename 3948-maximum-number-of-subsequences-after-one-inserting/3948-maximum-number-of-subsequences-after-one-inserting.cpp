class Solution {
public:
    long long numOfSubsequences(string s) {
        #define int long long
        vector<int> suff(s.length());
        int cnt=0;
        int n=s.length();
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='T'){
                cnt++;
            }
            suff[i]=cnt;

        }
        suff.push_back(0);
        cnt=0;
        int ans=0;
        int normans=0;
        int normans2=0;
        int normans3=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                cnt++;
            }
            int ans1=cnt*(suff[i+1]);
            ans=max(ans,ans1);
            if(s[i]=='C'){
                int ans2=(cnt+1)*suff[i+1];
                int ans3=(cnt)*(suff[i+1]+1);
                normans+=cnt*(suff[i+1]);
                normans2+=ans2;
                normans3+=ans3;
            }
        }
        
        return max({normans+ans,normans2,normans3});
        #undef int
        
    }
};