class Solution {
public:
    string removeba(string s,stack<char> st,int & points,int y){
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()=='b' && s[i]=='a'){
                st.pop();
                points=points+y;
            }
            else{
                st.push(s[i]);

            }
            
        }
            string rev;
            while(!st.empty()){
                char c=st.top();
                rev.push_back(c);
                st.pop();
            }
            reverse(rev.begin(),rev.end());
        return rev;
    }
    string removeab(string s,stack<char> st,int & points,int x){
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()=='a' && s[i]=='b'){
                st.pop();
                points=points+x;
            }
            else{
                st.push(s[i]);

            }
            
        }
            string rev;
            while(!st.empty()){
                char c=st.top();
                rev.push_back(c);
                st.pop();
            }
            reverse(rev.begin(),rev.end());
        return rev;
    }

    int maximumGain(string s, int x, int y) {
        int points=0;
        stack<char> st;
        if(y>x){
            string b=removeba(s,st,points,y);
            string j=removeab(b,st,points,x);
        }
        else{
            string b=removeab(s,st,points,x);
            string j=removeba(b,st,points,y);
            
        }
    return points;  
    }
};