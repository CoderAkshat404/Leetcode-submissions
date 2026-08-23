class Solution {
public:
    int spf[100100];
    int dist=0;
    map<int,set<int>>factors;
    set<int> findfactors(int n){
        set<int> v;
        int temp=n;
        while(temp>1){
            v.insert(spf[temp]);
            temp=temp/spf[temp];
        }
        return v;

    }
    void precomp(){
        for(int i=1;i<=100000;i++){
            spf[i]=i;
        }
        for(int i=2;i<=100000;i++){
            if(spf[i]==i){
                for(int j=2*i;j<=100000;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }

    }
    int countdist( unordered_map<int,int>&m,int n){
        int cnt=dist;
        for(auto i:factors[n]){
            if(m[i]==0){
                cnt++;
            }   
        }
        return cnt;


    }
    int longestSubarray(vector<int>& nums, int k) {
        precomp();
        for(auto i:nums){
            if(factors.find(i)==factors.end()){
                factors[i]=findfactors(i);
            }
        }
        unordered_map<int,int> m;
        int l=0;
        int r=-1;
        int ans=0;
        int n=nums.size();
        while(l<n){
            while(r+1<n && countdist(m,nums[r+1])<=k){
                r++;
                for(auto i:factors[nums[r]]){
                    if(m[i]==0){
                        dist++;
                    }
                    m[i]++;
                }    
            }
            ans=max(ans,r-l+1);
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                for(auto i:factors[nums[l]]){
                    m[i]--;
                    if(m[i]==0){
                        dist--;
                    }
                }
                l++;
            }

        }
        return ans;
        


        
    }
};