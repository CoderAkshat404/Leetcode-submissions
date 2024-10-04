class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        bool flag=true;
        long long int ans=0;
        int x=skill[0]+skill[j];
        while(i<j){
            if(skill[i]+skill[j]!=x){
                flag=false;
                break;
            }
            else{
                ans+=skill[i]*skill[j];
            }
            i++;
            j--;
        }
        if(flag){
            return ans;

        }
        else{
            return -1;
        }
        
    }
};