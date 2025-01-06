class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v;
        for(int i=0;i<boxes.length();i++){
            int count=0;
            for(int j=0;j<boxes.length();j++){
                if(boxes[j]=='1'){
                    count=count+fabs(j-i);
                }
            }
            v.push_back(count);
        }
        return v;
        
    }
};