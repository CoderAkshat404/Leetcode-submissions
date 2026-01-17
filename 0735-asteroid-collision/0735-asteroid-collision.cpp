class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<a.size();i++){
            if(a[i]<0){
                while(!s.empty() && s.top()<abs(a[i])){
                    s.pop();
                }
                if(!s.empty() && s.top()==abs(a[i])){
                    s.pop();
                }
                else if(s.empty()){
                    ans.push_back(a[i]);

                }
                
            }
            else{
                s.push(a[i]);
            }
        }
        int n=ans.size();
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin()+n,ans.end());
        return ans;

    }
};