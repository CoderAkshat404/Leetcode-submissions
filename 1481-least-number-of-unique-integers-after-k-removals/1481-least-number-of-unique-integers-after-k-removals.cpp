class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        for(auto i:arr){
            m[i]++;
        }
        vector<pair<int,int>> v;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            if(v[i].first<=k){
                k-=v[i].first;
                v[i].first=0;
               
            }
            else{
                break;
            }
        }
        int ans=0;
        for(auto i:v){
            
            if(i.first>0) ans++;
        }
        return ans;
        
    }
};