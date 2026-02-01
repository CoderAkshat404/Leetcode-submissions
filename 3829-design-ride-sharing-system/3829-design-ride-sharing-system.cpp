class RideSharingSystem {
public:
    map<int,int> m;
    set<pair<int,int>> driver;
    set<pair<int,int>> rider;
    int cntr=0;
    int cntd=0;

    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.insert({cntr,riderId});
        m[riderId]=cntr;
        cntr++;
        
    }
    
    void addDriver(int driverId) {
        driver.insert({cntd,driverId});
        cntd++;
        
    }
    
    vector<int> matchDriverWithRider() {
        if(!rider.empty() && !driver.empty()){
            int riderId=(*rider.begin()).second;
            int driverId=(*driver.begin()).second;
            rider.erase(rider.begin());
            driver.erase(driver.begin());
            return {driverId,riderId};

        }
        return {-1,-1};
        
    }
    
    void cancelRider(int riderId) {
        int cntr=m[riderId];
        pair<int,int> p={cntr,riderId};
        rider.erase(p);
        
        
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */