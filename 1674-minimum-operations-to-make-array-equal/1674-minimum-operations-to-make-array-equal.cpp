class Solution {
public:
    int minOperations(int n) {
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=(2*i)+1;
        }
        int count=0;
        if(n&1){
            int mid=n/2;
            for(int i=0;i<mid;i++){
                count+=v[mid]-v[i];
            }

        }
        else{
            int mid=n/2;
            for(int i=0;i<mid-1;i++){
                count+=(v[mid]-1)-v[i];
            }
            count++;

        }
        

    return count;    
    }
};