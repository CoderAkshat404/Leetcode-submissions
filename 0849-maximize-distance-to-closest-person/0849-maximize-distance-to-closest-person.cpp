class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> ones;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                ones.push_back(i);
            }
        }
        int maxi=0;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==0){
                int left=-1;
                int right=-1;
                left=lower_bound(ones.begin(),ones.end(),i)-ones.begin();
                left--;

                int dist=1e9;
                if(left>=0){
                   
                    dist=min(dist,i-ones[left]);
                }
                right=lower_bound(ones.begin(),ones.end(),i)-ones.begin();
                if(right<ones.size()){
                     dist=min(dist,ones[right]-i);

                }
                maxi=max(maxi,dist);
               

            }
        }
        return maxi;
        
    }
};