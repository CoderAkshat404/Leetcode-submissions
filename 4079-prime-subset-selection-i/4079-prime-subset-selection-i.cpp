class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> spf(n+1,1);
        for(int i=2;i<=n;i++){
            if(spf[i]==1){
                for(int j=2*i;j<=n;j+=i){
                    if(spf[j]==1){
                        spf[j]=0;
                    }
                }
            }
        }
        vector<int> ans;
        int currsum=0;
        for(int i=2;i<=n;i++){
            if(spf[i]==1 && currsum+i<=s){
                currsum+=i;
                ans.push_back(i);
            }
        }
        return ans;

    }
};