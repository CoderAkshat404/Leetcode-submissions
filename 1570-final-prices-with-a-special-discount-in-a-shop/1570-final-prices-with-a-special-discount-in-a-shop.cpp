class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i=0;i<prices.size()-1;i++){
            int ele=prices[i];
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=ele){
                    ele=ele-prices[j];
                    break;
                }
            }
            ans.push_back(ele);
        }
        ans.push_back(prices[prices.size()-1]);
        return ans;
        
    }
};