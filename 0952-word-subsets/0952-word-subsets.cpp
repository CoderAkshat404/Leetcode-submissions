class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> m;
        vector<string> ans;
        for(int i=0;i<words2.size();i++){
            for(int k=0;k<words2[i].length();k++){
                int x=count(words2[i].begin(),words2[i].end(),words2[i][k]);
                m[words2[i][k]]=max(m[words2[i][k]],x);

            }
        }
        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        for(int i=0;i<words1.size();i++){
            bool flag=true;
            for(auto j:m){
                char c=j.first;
                int x=count(words1[i].begin(),words1[i].end(),c);
                if(x<j.second){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(words1[i]);
            }

        }
     return ans;   
    }
};