class Solution {
public:
    int minOperations(int k) {
        int mini=1e9;
        int curr=1;
        while(curr<=k){
            mini=min(mini,(curr-1)+((k+curr-1)/curr));
            curr++;
        }
        return mini-1;
        
    }
};