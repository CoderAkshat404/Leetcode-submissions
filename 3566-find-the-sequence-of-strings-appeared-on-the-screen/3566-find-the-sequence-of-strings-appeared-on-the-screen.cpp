class Solution {
public:
    vector<string> stringSequence(string target) {
        string s="";
        int j=0;
        vector<string> ans;
        while(j<target.size()){
            s+='a';
            ans.push_back(s);
            while(s[j]!=target[j]){
                s[j]=char(int(s[j])+1);
                ans.push_back(s);
            }
            j++;
        }
        return ans;

        
    }
};