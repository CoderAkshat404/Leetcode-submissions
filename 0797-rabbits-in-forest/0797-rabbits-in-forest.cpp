class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<answers.size();i++){
            if(answers[i]!=0){
                m[answers[i]]++;
            }
            else if(answers[i]==0){
                ans+=1;
            }

        }
        for(auto i:m){
            ans+=((i.second+i.first)/(i.first+1))*(i.first+1);
        }
        return ans;
        
    }
};