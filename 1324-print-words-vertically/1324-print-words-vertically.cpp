class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        stringstream ss(s);
        string inp;
        int maxi=0;
        while(ss>>inp){
            words.push_back(inp);
            maxi=max(maxi,(int)inp.length());
        }
        // for(auto i:words){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        vector<string> ans(maxi,"");
        for(int i=0;i<words.size();i++){
            for(int j=0;j<maxi;j++){
                if(j<words[i].length()){
                    ans[j]+=words[i][j];
                }
                else{
                    ans[j]+=' ';
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            while(ans[i].back()==' '){
                ans[i].pop_back();
            }

        }
        return ans;

        
    }
};