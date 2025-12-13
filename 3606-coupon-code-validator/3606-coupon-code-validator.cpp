class Solution {
public:
    bool check1(string s){
        if(s==""){
            return false;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                continue;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                continue;
            }
            else if(s[i]>='0' && s[i]<='9'){
                continue;
            }
            else if(s[i]=='_'){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool check2(string s){
        return (s=="electronics") || (s=="grocery") || (s=="pharmacy") || (s=="restaurant");
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<int> valid;
        for(int i=0;i<businessLine.size();i++){
            if(check1(code[i]) && check2(businessLine[i]) && isActive[i]){
                valid.push_back(i);
            }
        }
        vector<string> el;
        vector<string> gr;
        vector<string> ph;
        vector<string> rs;
        for(int i=0;i<valid.size();i++){
            if(businessLine[valid[i]]=="electronics"){
                el.push_back(code[valid[i]]);
            }
            else if(businessLine[valid[i]]=="grocery"){
                gr.push_back(code[valid[i]]);
            }
            else if(businessLine[valid[i]]=="pharmacy"){
                ph.push_back(code[valid[i]]);
            }
            else if(businessLine[valid[i]]=="restaurant"){
                rs.push_back(code[valid[i]]);
            }
        }
        sort(el.begin(),el.end());
        sort(gr.begin(),gr.end());
        sort(ph.begin(),ph.end());
        sort(rs.begin(),rs.end());
        vector<string> ans;
        for(int i=0;i<el.size();i++){
            ans.push_back(el[i]);
        }
        for(int i=0;i<gr.size();i++){
            ans.push_back(gr[i]);
        }
        for(int i=0;i<ph.size();i++){
            ans.push_back(ph[i]);
        }
        for(int i=0;i<rs.size();i++){
            ans.push_back(rs[i]);
        }
        return ans;
        
        
        
    }
};