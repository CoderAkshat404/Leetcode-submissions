class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> v;
        int ans=0;
        for(int i=0;i<strs[0].size();i++){
            bool flag=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]<strs[j-1][i] && v.size()==0){
                    flag=false;
                    break;

                }
                
                else if(strs[j][i]<strs[j-1][i]){
                    bool flag2=true;
                    for(int prev:v){
                    if(strs[j][prev]!=strs[j-1][prev]){
                        flag2=false;
                        break;
                    }
                    }
                    if(flag2){
                        flag=false;
                        break;
                    }
                }

            }
            if(!flag){
                
                ans++;
            }
            else{
                v.push_back(i);
            }

        }
        return ans;
        
    }
};