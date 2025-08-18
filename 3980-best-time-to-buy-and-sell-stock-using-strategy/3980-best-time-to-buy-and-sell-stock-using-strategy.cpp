class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        #define int long long
        vector<int> pre;
        int val=0;
        for(int i=0;i<k;i++){
            val+= prices[i]*strategy[i];
        }
        pre.push_back(val);
        int i=0;
        int j=k-1;
        while(j+1<prices.size()){
            val+=prices[j+1]*strategy[j+1];
            val-=prices[i]*strategy[i];
            i++;
            j++;
            pre.push_back(val);
        }
        int ans=0;
        for(int i=0;i<prices.size();i++){
            ans+=prices[i]*strategy[i];
        }
        val=0;
        for(int i=k/2;i<k;i++){
            val+=prices[i];
        }
        int maxi=0;
        int p=0;
        maxi=max(maxi,val-pre[p]);
        p++;
        i=k/2;
        j=k-1;
        while(j+1<prices.size()){
            val+=prices[j+1];
            val-=prices[i];
            i++;
            j++;
             maxi=max(maxi,val-pre[p]);
            p++;

        }
        return maxi+ans;
        #undef int

        
    }
};