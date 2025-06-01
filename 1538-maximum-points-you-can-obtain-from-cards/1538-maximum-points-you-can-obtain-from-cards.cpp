class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int mini=INT_MAX;
        int total=0;
        for(auto i:cardPoints){
            total+=i;
        }
        if(k==n){
            return total;
        }
        int currsum=0;
        for(int i=0;i<n-k;i++){
            currsum+=cardPoints[i];
        }
    
        mini=min(mini,currsum);
     
        int i=0;
        int j=n-k-1;
        while(j<n-1){
            currsum+=cardPoints[j+1];
            currsum-=cardPoints[i];
            i++;
            j++;
            mini=min(mini,currsum);
        }
        return total-mini;
        
    }
};