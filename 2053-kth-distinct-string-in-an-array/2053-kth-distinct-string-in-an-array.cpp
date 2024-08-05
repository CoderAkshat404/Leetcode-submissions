class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        unordered_map<string,int> mp;
        unordered_map<string,bool> m3;
        
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
            if(m3[arr[i]]==false){
                mp[arr[i]]=i;
                m3[arr[i]]=true;
            }
        }
        vector<int> idx;
        for(auto i:m){
            if(i.second==1){
                idx.push_back(mp[i.first]);
            }
        }
        sort(idx.begin(),idx.end());
        if(idx.size()<k){
            return "";
        }
        else{
            int ans=idx[k-1];
            return arr[ans];
        }
        
        
    }
};