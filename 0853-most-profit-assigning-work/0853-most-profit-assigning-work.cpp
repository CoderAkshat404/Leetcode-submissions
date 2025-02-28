class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        for(int i=0;i<difficulty.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        vector<int> h;
        int maxi=INT_MIN;
        for(int i=0;i<difficulty.size();i++){
            maxi=max(maxi,v[i].second);
            h.push_back(maxi);
        }
        int sum=0;
        for(int i=0;i<worker.size();i++){
            int tar=worker[i];
            int lo=0;
            int hi=v.size()-1;
            int ans=-1;
            while(lo<=hi){
                int m=lo+(hi-lo)/2;
                if(v[m].first>tar){
                    hi=m-1;
                }
                else{
                    ans=m;
                    lo=m+1;
                }
            }
            if(ans==-1){
                sum+=0;
            }
            else{
                sum+=h[ans];
            }


        }
        return sum;
        
    }
};