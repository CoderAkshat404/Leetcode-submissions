class Solution {
public:
    static bool cmp(int a,int b){
        string x=to_string(a);
        string y=to_string(b);
        return (x+y)>(y+x);
    }
    string largestNumber(vector<int>& arr) {
         sort(arr.begin(),arr.end(),cmp);
        string ans="";
        for(auto i:arr){
            ans+=to_string(i);
        }
        if(count(ans.begin(),ans.end(),'0')==ans.length()){
            return "0";
        }
        return ans;
        
    }
};