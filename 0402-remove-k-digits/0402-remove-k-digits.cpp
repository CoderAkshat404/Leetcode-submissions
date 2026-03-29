class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(auto i:num){
            
            if(ans==""){
                ans+=i;
            }
            else{
                while(ans!="" && ans.back()>i &&k>0){
                    ans.pop_back();
                    k--;
                    if(k==0){
                        break;
                    }
                }
                ans+=i;
            }
            // cout<<ans<<endl;
        }
        while(k>0){
            k--;
            ans.pop_back();
            if(ans=="") break;
        }
        reverse(ans.begin(),ans.end());
        while(ans!="" &&ans.back()=='0'){
            ans.pop_back();
        }
         reverse(ans.begin(),ans.end());
         if(ans=="") return "0";
         else{
            return ans;
         }
        
    }
};