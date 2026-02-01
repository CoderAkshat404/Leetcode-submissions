class Solution {
public:
    int countMonobit(int n) {
        if(n==0){
            return 1;
        }
        int x=0;
        if((n&(n+1))==0){
            x=1;
        }
        cout<<x<<endl;
        return 1+log2(n)+x;
        
    }
};