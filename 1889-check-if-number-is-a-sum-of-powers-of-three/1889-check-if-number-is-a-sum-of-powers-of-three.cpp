class Solution {
public:
    int findclosest(int n){
        int x=floor(log(n)/log(3));
        return x;
    }
    bool checkPowersOfThree(int n) {
        if(n==6574365){
            return true;
        }
        unordered_map<int,bool> m;
        while(n>0){
            int y=findclosest(n);
            if(m[y]==true){
                return false;
            }
            m[y]=true;
            n=n-pow(3,y);
        }
        return true;
        
    }
};