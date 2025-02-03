class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int oddm=INT_MIN;
        int evenm=INT_MAX;
        for(auto i:m){
            if(i.second&1){
                oddm=max(oddm,i.second);
            }
            else{
                evenm=min(evenm,i.second);
            }
        }
        return oddm-evenm;
        
    }
};