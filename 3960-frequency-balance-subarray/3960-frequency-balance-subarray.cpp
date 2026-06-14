class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            map<int,int> m;
            map<int,int> f;
            for(int j=i;j<n;j++){
                if(f.find(m[nums[j]])!=f.end()){
                    f[m[nums[j]]]--;
                    if(f[m[nums[j]]]==0){
                        f.erase(m[nums[j]]);
                    }
                }
                m[nums[j]]++;
                f[m[nums[j]]]++;
                
                if(m[nums[j]]==j-i+1){
                    
                    ans = max(j-i+1,ans);
                }else{
                    if(f.size()==2){
                       if((f.begin()->first) * 2 == (f.rbegin()->first)){
                    
                            ans = max(j-i+1,ans);
                        }
                    }
                }
            }
        }
        return ans;
                    // cout<<i<<" "<<j<<endl;
    }
};