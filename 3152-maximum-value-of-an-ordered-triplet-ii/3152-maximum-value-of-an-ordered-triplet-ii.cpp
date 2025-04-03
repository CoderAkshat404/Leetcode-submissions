#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<ll> mini;
        vector<ll> maxi;
        ll currmax=INT_MIN;
        ll currmin=INT_MAX;
        ll n=nums.size();
        for(ll i=n-1;i>=0;i--){
            currmax=max((ll)nums[i],currmax);
            maxi.push_back(currmax);    
        }
        // for(auto i:maxi) cout<<i<<" ";
        reverse(maxi.begin(),maxi.end());
        cout<<endl;
        ll ans=INT_MIN;
        ll x=nums[0];
        for(ll i=1;i<n-1;i++){
            ll y=(x-nums[i])*maxi[i+1];
            ans=max(ans,y);
            x=max((ll)nums[i],x);
        }
        if(ans<0) return 0;
        return ans;
        
    }
};