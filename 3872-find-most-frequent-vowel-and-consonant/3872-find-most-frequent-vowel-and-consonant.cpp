class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        int maxc=0;
        int maxv=0;
        for(auto i:m){
            if(i.first=='a' || i.first=='e' || i.first=='i' || i.first=='o' || i.first=='u'){
                maxv=max(maxv,i.second);
            }
            else{
                maxc=max(maxc,i.second);
            }
        }
        return maxc+maxv;
        
    }
};