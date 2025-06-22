class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string p="";
        int cnt=0;
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            p+=s[i];
            cnt++;
            if(cnt==k){
                ans.push_back(p);
                cnt=0;
                p="";
            }
        }
        if(cnt<k && cnt>0){
            int diff=k-cnt;
            while(diff--){
                p+=fill;
            }
            ans.push_back(p);
        }
        return ans;
        
    }
};