class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        map<char,int> m;
        map<int,char> mp;
        for(int i=0;i<26;i++){
            m[i+'a']=weights[i];
        }
        for(char ch='z';ch>='a';ch--){
            mp['z'-ch]=ch;
        }
        string ans="";
        for(int i=0;i<words.size();i++){
            int sum=0;
            for(auto j:words[i]){
                sum=(sum+m[j])%26;
                
            }
            
            ans+=mp[sum];
        }
        return ans;
        
    }
};