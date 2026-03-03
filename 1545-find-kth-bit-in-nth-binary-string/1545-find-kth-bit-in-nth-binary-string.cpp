class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1){
            return '0';
        }
        string curr="0";
        for(int i=0;i<n-1;i++){
            string p=curr;
            p+='1';
            for(int j=0;j<curr.length();j++){
                if(curr[j]=='0'){
                    curr[j]='1';
                }
                else{
                    curr[j]='0';
                }
            }
            reverse(curr.begin(),curr.end());
            p+=curr;
            curr=p;
        }
        return curr[k-1];
        
    }
};