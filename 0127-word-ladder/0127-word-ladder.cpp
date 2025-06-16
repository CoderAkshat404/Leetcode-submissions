class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordList) {
        int ans=INT_MAX;
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        unordered_map<string,bool> m;
        q.push({beginword,1});
        while(!q.empty()){

            string word=q.front().first;
            int dis=q.front().second;
            if(word==endword){
                ans=min(ans,dis);
            }
            q.pop();
            for(int i=0;i<word.length();i++){
                char c=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end() && m.find(word)==m.end()){
                        m[word]=true;
                        q.push({word,dis+1});
        
                    }    
                }
                word[i]=c;
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
      return ans;  
    }
};