class Solution {
public:
    vector<int> findnge(vector<int>& t){
        int n=t.size();
        vector<int> nge(t.size());
        nge[n-1]=n;
        for(int i=n-2;i>=0;i--){
            int ans=i+1;
            while(ans!=n && t[ans]<=t[i]){
                ans=nge[ans];
            }
            nge[i]=ans;
        }
        return nge;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v=findnge(temperatures);
        vector<int> ans;
        int n=temperatures.size();
        for(int i=0;i<temperatures.size();i++){
            if(v[i]==n){
                ans.push_back(0);
            }
            else {
                ans.push_back(v[i]-i);
            }
        }
        return ans;
        
    }
};