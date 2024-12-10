class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        for(int i=0;i<n;i++){
            int e=(2*i)+start;
            ans=ans^e;

        }
    return ans;    
    }
};