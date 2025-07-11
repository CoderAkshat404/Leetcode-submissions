class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> duration;
        for(int i=0;i<startTime.size();i++){
            duration.push_back(endTime[i]-startTime[i]);
        }
        vector<int> freeslot;
        freeslot.push_back(startTime[0]);
        for(int i=0;i<startTime.size()-1;i++){
            freeslot.push_back(startTime[i+1]-endTime[i]);
        }
        freeslot.push_back(eventTime-endTime.back());
        // for(auto i:freeslot){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:duration){
        //     cout<<i<<" ";

        // }
        // cout<<endl;
        int maxi=0;
        for(int i=0;i<freeslot.size()-1;i++){
            maxi=max(maxi,freeslot[i]+freeslot[i+1]);
        }
        int n=freeslot.size();
        vector<int> pre(n);
        vector<int> suff(n);
        pre[0]=freeslot[0];
        for(int i=1;i<n;i++){
            pre[i]=max(freeslot[i],pre[i-1]);
        }
        suff[n-1]=freeslot[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=max(freeslot[i],suff[i+1]);
        }
        // for(auto i:suff){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i:pre){
        //     cout<<i<<" ";
        // }
        for(int i=0;i<duration.size();i++){
            if((i+2<n) && suff[i+2]>=duration[i]){
                maxi=max(maxi,freeslot[i]+freeslot[i+1]+duration[i]);
            }
            if(i>0 && pre[i-1]>=duration[i]){
                maxi=max(maxi,freeslot[i]+freeslot[i+1]+duration[i]);
            }
        }
        return maxi;
        
    }
};