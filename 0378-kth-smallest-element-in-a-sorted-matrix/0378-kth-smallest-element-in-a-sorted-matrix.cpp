class Solution {
public:
    int check(int mid,vector<vector<int>>& matrix, int k){
        int cnt=0;
        for(int i=0;i<matrix.size();i++){
            cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
        }
        return cnt>=k;

    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo=-1e9;
        int hi=1e9;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,matrix,k)){
                hi=mid-1;
                ans=mid;

            }
            else{
                lo=mid+1;
                
            }
        }
        return ans;
        
    }
};