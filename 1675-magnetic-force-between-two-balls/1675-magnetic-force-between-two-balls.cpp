class Solution {
public:
    int check(int m,int mid,vector<int>& position){
        int lp=position[0];
        m--;
        for(int i=1;i<position.size();i++){
            if(position[i]-lp>=mid){
                m--;
                lp=position[i];
            }
        }
        if(m<=0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo=1;
        int hi=position[position.size()-1]-position[0];
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(m,mid,position)==1){
                lo=mid+1;
                ans=mid;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
        
    }
};