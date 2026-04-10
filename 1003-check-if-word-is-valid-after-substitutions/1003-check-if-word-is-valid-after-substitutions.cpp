class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(auto i:s){
            if(i!='c'){
                v.push_back(i);
            }
            else{
                if(v.size()>=2){
                    int n=v.size();
                    bool flag=false;
                    if(v[n-1]=='b' && v[n-2]=='a'){
                        flag=true;
                    }
                    if(flag){
                        v.pop_back();
                        v.pop_back();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return (v.size()==0);
        
    }
};