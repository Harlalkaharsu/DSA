class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas =0, totalcost =0;
        for(int i=0; i< gas.size(); i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }

        if(totalgas < totalcost) return -1;

        int currentgas =0, start =0;
        for(int i =0; i< gas.size(); i++){
            currentgas += gas[i] - cost[i];
            if(currentgas <0){
                currentgas =0;
                start = i+1;
            }
        }
        return start;
    }
};