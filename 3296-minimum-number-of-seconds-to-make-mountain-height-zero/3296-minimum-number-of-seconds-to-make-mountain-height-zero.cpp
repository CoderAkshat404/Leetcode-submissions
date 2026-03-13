#define ll long long
class Solution {
public:
    vector<ll> v;
    bool check(ll m,int h,vector<int>& wt){
        ll x=0;
        for(int i=0;i<wt.size();i++){
            ll a=(m/wt[i]);
            x+=(upper_bound(v.begin(),v.end(),a)-v.begin());   
           
        }
        return x>=h;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll s=0;
        for(int i=1;i<=1e5;i++){
            s+=i;
            v.push_back(s);   
        }
        ll lo=1;
        ll hi=1e18;
        ll ans=-1;
        while(lo<=hi){
            ll mid=lo+(hi-lo)/2;
            if(check(mid,mountainHeight,workerTimes)){
                hi=mid-1;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return  ans;
        
        
        
    }
};