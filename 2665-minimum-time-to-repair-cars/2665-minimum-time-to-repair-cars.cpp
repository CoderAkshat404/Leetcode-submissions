#define ll long long
class Solution {
public:
    bool check(vector<int>& r,ll mid,int cars){
        long long sum = 0;
        for(ll i:r){
            ll x = mid/i;
            ll y = sqrtl(x);
            sum = sum + y;
        }
        return (sum>=cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long n = ranks.size();
        int maxi = 0;
        for(ll i = 0; i<n;i++){
            if(maxi<ranks[i]){
                maxi = ranks[i];
            }
        }
        ll ans = 0;
        ll s = 1, e = 1LL*maxi*cars*cars;
        while(s<=e){
            ll mid = s + (e-s)/2;
            if(check(ranks,mid,cars)){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return ans;
    }
};