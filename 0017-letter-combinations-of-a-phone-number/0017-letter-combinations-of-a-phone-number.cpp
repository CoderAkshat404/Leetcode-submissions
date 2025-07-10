class Solution {
public:
    vector<string> ans;
    string p;
    void rec(int i,string&digits,unordered_map<int,string>&m){
        if(i==digits.size()){
            if(p.length()>0)
            ans.push_back(p);
            return;

        }
        string a=m[digits[i]-'0'];
        for(int j=0;j<a.size();j++){
            p.push_back(a[j]);
            rec(i+1,digits,m);
            p.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        rec(0,digits,m);
        return ans;


        
    }
};