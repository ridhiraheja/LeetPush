class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long totalMass=mass;
        for(int &asteroid:asteroids){
            if(totalMass<asteroid){
                return false;
            }
            totalMass+=asteroid;
        }
        return true;
        
    }
};