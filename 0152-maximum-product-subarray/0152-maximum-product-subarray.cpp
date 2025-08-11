class Solution {
public:
    int maxProduct(vector<int>& nums) {
        set<int> pos;
        set<int> neg;
        pos.insert(1);
        neg.insert(1);
        int pro=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            // cout<<pos.size()<<" "<<neg.size()<<endl;
            pro=pro*nums[i];
            if(pro>=0){
                maxi=max(maxi,(pro/(*pos.begin())));
            }
            else{
                maxi=max(maxi,(pro/(*neg.rbegin())));
            }
            maxi=max(maxi,pro);
            if(pro>0){
                pos.insert(pro);
            }
            if(pro<0){
                neg.insert(pro);
                neg.erase(1);
            }
            if(pro==0){
                pro=1;
                pos.clear();
                neg.clear();
                pos.insert(1);
                neg.insert(1);
            }
        }
        return maxi;
        
    }
};