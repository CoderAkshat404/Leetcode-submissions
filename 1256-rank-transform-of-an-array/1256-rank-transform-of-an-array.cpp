class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a=arr;
        sort(a.begin(),a.end());
        unordered_map<int,int> m;
        unordered_map<int,bool> mp;
        int rank=1;
        for(int i=0;i<a.size();i++){
            if(mp[a[i]]==false){
                m[a[i]]=rank;
                mp[a[i]]=true;
                rank++;
            }

        }
        for(auto i:m){
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=m[arr[i]];
        }
        return arr;        
    }
};