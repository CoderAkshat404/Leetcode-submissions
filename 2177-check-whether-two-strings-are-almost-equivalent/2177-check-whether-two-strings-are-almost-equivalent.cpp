class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto i:word1){
            m1[i]++;
        }
        for(auto i:word2){
            m2[i]++;
        }
        bool flag=true;
        for(auto i:m1){
            if(abs(i.second-m2[i.first])>3){
                flag=false;
                break;
            }
        }
        for(auto i:m2){
            if(abs(i.second-m1[i.first])>3){
                flag=false;
                break;
            }
        }
        return flag;


        
    }
};