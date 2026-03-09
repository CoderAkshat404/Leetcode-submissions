class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx=-1;
        int mini=1e9;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize){
                if(capacity[i]<mini){
                    mini=capacity[i];
                    idx=i;
                }
            }
        }
        return idx;
        
    }
};