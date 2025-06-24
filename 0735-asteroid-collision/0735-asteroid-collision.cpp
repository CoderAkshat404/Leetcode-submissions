class Solution {
public:
    vector<int> asteroidCollision(vector<int>&v) {
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(v[i]<0){
                while(!s.empty() && s.top()<abs(v[i]) && s.top()>0){
                    s.pop();
                }
                if(s.size()==1 && s.top()==abs(v[i])){
                    s.pop();
                    continue;
                } 
                if(!s.empty() && s.top()==abs(v[i])){
                    s.pop();
                    continue;
                }
                if(s.empty()){
                    s.push(v[i]);
                }
                else if(s.top()<0){
                    s.push(v[i]);
                }
            }
            else{
                s.push(v[i]);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};