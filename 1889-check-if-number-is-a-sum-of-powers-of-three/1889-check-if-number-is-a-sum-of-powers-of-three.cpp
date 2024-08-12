class Solution {
public:
int findclosest(int n) {
    int x = 0;
    while (pow(3, x + 1) <= n) {
        x++;
    }
    return x;
}

    bool checkPowersOfThree(int n) {
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