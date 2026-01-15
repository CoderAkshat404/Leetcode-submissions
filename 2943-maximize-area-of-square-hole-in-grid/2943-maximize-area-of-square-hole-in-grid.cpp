class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxih=0;
        int cnt=0;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int prev=hBars[0]-1;
        for(int i=0;i<hBars.size();i++){
            if(hBars[i]-1==prev){
                prev=hBars[i];
                cnt++;
                maxih=max(maxih,cnt);  
            }
            else{
                cnt=1;
                prev=hBars[i];
            }
        }
        int maxiv=0;
        cnt=0;
        prev=vBars[0]-1;
        for(int i=0;i<vBars.size();i++){
            if(vBars[i]-1==prev){
                prev=vBars[i];
                cnt++;
                maxiv=max(maxiv,cnt);  
            }
            else{
                cnt=1;
                prev=vBars[i];
            }
        }
        return (min(maxiv,maxih)+1)*(min(maxiv,maxih)+1);
    }
};