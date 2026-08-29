class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sn=abs(source[0]-source[1]);
        int tn=abs(target[0]-target[1]);
        if(sn%2!=tn%2) return -1;
        if(abs(source[0]-target[0])==abs(source[1]-target[1])){
            return 1;
        }
        return 2;
        
    }
};