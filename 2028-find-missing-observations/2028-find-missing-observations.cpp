class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int tot=0;
        for(auto i:rolls){
            tot+=i;
        }
        int sum=mean*(rolls.size()+n)-tot;
        if(sum>6*n) return {};
        if(sum<n) return {};
        int avg=sum/n;
        vector<int> ans;
        for(int i=0;i<n-1;i++){
            ans.push_back(avg);
            sum-=avg;

        }
        if(sum>6){
            for(int i=0;i<n-1;i++){
                if(sum==1){
                    break;
                }
                int left=6-ans[i];
                if(sum-left>=1){
                    ans[i]=6;
                    sum-=left;
                }
            }
            
        }
        ans.push_back(sum);
        return ans;
        
    }
};