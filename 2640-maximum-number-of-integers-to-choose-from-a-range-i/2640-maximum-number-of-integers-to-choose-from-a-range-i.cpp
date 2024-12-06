class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum=0;
        int ans=0;
        unordered_map<int,bool> m;
        for(int i=0;i<banned.size();i++){
            m[banned[i]]=true;
        }
        if(n==0){
            return 0;
        }
        int i=1;
        while(sum+i<=maxSum){
            if(m[i]==false){
                sum+=i;
                ans++;
            }
            
            i++;
            if(i>n){
                break;
            }
        }
        return ans;
        
    }
};