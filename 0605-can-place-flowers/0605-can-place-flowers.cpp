class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int tot) {
        int n=f.size();
        int x=0;
        if(n==1){
            if(f.back()==0){
                x++;
            }
        }
        if(f.size()>=2){
            if(f[0]==0 && f[1]==0){
                f[0]=1;
                x++;
            }
        }
        for(int i=1;i<n-1;i++){
            if(f[i]==0 && f[i-1]==0 && f[i+1]==0){
                f[i]=1;
                x++;
            }
        }
         if(f.size()>=2){
            if(f.back()==0 && f[n-2]==0){
                x++;
            }
        }
        return x>=tot;

        
    }
};