class Solution {
public:
    vector<int> vowelStrings(vector<string>& word, vector<vector<int>>& queries) {
        vector<int> fav(word.size());
        for(int i=0;i<word.size();i++){
            if((word[i][0]=='a' ||word[i][0]=='e' ||word[i][0]=='i' ||word[i][0]=='o' ||word[i][0]=='u')&&(word[i][word[i].length()-1]=='a' ||word[i][word[i].length()-1]=='e' ||word[i][word[i].length()-1]=='i' ||word[i][word[i].length()-1]=='o' ||word[i][word[i].length()-1]=='u' )){
                fav[i]=1;
            }
            else{
                fav[i]=0;
            }
        }
        for(auto i:fav){
            cout<<i<<" ";
        }
        cout<<endl;
        vector<int> pre(word.size(),-1);
        pre[0]=fav[0];
        for(int i=1;i<word.size();i++){
            pre[i]=pre[i-1]+fav[i];

        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int a;
            if(queries[i][0]>0){
                a=pre[queries[i][1]]-pre[queries[i][0]-1];
            }
            else{
                a=a=pre[queries[i][1]]-0;
            }
            ans.push_back(a);
        } 
        return ans;
    }
};