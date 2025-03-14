class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            int x=q.front().second;
            string s=q.front().first;
            q.pop();
            if(s==endWord) return x;
            for(int i=0;i<s.length();i++){
                char c=s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s,x+1});
                    }
                }
                s[i]=c;
            }
        }
        return 0;
        
    }
};