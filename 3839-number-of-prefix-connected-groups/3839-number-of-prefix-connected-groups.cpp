class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int> m;
        for(int i=0;i<words.size();i++){
            if(words[i].length()<k){
                continue;
            }
            else{
                string s=words[i].substr(0,k);
                m[s]++;
            }
        }
        int ans=0;
        for(auto i:m){
            if(i.second>=2){
                ans++;
            }
        }
        return ans;
        
    }
};