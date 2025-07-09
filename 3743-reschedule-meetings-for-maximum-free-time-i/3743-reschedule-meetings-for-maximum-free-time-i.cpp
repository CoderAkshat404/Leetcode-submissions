class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freetime;
        int st=0;
        int n=endTime.size();
        for(int i=0;i<n;i++){
            freetime.push_back(startTime[i]-st);
            st=endTime[i];
        }
        freetime.push_back(eventTime-endTime.back());
        // for(auto i:freetime){
        //     cout<<i<<" ";
        // }
        int maxi=-1;
        int sum=0;
        for(int i=0;i<k+1;i++){
            sum+=freetime[i];
        }
        maxi=max(maxi,sum);
        int i=0;
        int j=k;
        while(j+1<freetime.size()){
            sum+=freetime[j+1];
            sum-=freetime[i];
            i++;
            j++;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};