class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int ones = 0;
        for(auto i:s){
            if(i=='1'){
                ones++;
            }

        }
        int z = n-ones;

        int mini = 1e9;
        mini = min(z,mini);
        mini = min(ones,mini);
        mini = min(ones-1,mini);

        int x=0;
        for(int i=1;i<n-1;i++){
            if(s[i]=='1'){
                x++;
            }
        }
        mini = min(x,mini);

        return max(0,mini);
    

    }
};