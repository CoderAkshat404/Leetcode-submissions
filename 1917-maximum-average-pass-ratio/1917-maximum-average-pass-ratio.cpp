class Solution {
public:
    struct Comp {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) const {
        double g1 = (double)(p1.first + 1) / (p1.second + 1) - (double)p1.first / p1.second;
        double g2 = (double)(p2.first + 1) / (p2.second + 1) - (double)p2.first / p2.second;
        return g1 < g2; 
    }
};

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> pq;
        for(int i=0;i<classes.size();i++){
            pq.push({classes[i][0],classes[i][1]});
        }
        while(extraStudents--){
            int x=pq.top().first;
            int y=pq.top().second;
            pq.pop();
            pq.push({x+1,y+1});
        }
        double ans=0;
        while(!pq.empty()){
            double x=pq.top().first;
            double y=pq.top().second;;
            ans+=(double)x/y;
            pq.pop();
        }
        return (double)ans/(double)classes.size();
        
    }
};