#define ll long long
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<ll> h;
        vector<ll> v;
        for(int i=0;i<grid.size();i++){
            ll sum=0;
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];

            }
            h.push_back(sum);
        }
        for(int i=0;i<grid[0].size();i++){
            ll sum=0;
            for(int j=0;j<grid.size();j++){
                sum+=grid[j][i];
            }
            v.push_back(sum);
        }
        vector<ll> pre(h.size());
        pre[0]=h[0];
        for(int i=1;i<h.size();i++){
            pre[i]=pre[i-1]+h[i];
        }
        vector<ll> pre2(v.size());
        pre2[0]=v[0];
        for(int i=1;i<v.size();i++){
            pre2[i]=pre2[i-1]+v[i];
        }
        ll total=pre.back();
        bool flag=false;
        for(int i=0;i<pre.size();i++){
            ll curr=pre[i];
            ll rem=total-curr;
            if(curr==rem){
                flag=true;
                break;
            }
        }
        for(int i=0;i<pre2.size();i++){
            ll curr=pre2[i];
            ll rem=total-curr;
            if(curr==rem){
                flag=true;
                break;
            }
        }
        return flag;


        
    }
};