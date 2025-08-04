class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0;
        int r=-1;
        unordered_map<int,int> m;
        int ans=0;
        int dist=0;
        while(l<n){
            while(r+1<n && (dist<2 || (dist==2 && m[fruits[r+1]]>0))){
                r++;
                m[fruits[r]]++;
                if(m[fruits[r]]==1){
                    dist++;
                }
            }
            ans=max(ans,r-l+1);
            if(r<l){
                l++;
                r=l-1;
            }
            else{
                m[fruits[l]]--;
                if(m[fruits[l]]==0){
                    dist--;
                }
                l++;
            }
        }
        return ans;
        
        
    }
};