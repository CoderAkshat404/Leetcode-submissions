int MOD=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse(n);
        vector<int> pse(n);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push({arr[i],i});
                pse[i]=-1;
            }
            else{
                while(!s.empty() && s.top().first>arr[i]){
                    s.pop();
                }
                if(!s.empty()){
                    pse[i]=s.top().second;
                }
                else{
                    pse[i]=-1;
                }
                s.push({arr[i],i});
            }
        }
        stack<pair<int,int>> a;
        for(int i=n-1;i>=0;i--){
            if(a.empty()){
                a.push({arr[i],i});
                nse[i]=n;
            }
            else{
                while(!a.empty() && a.top().first>=arr[i]){
                    a.pop();
                }
                if(!a.empty()){
                    nse[i]=a.top().second;
                }
                else{
                    nse[i]=n;
                }
                a.push({arr[i],i});
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            ans=(ans+((long long)1*left*right*arr[i])%MOD)%MOD;

        }
        return ans;

        
    }
};