class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> ratio;
        priority_queue<pair<int,int>> pq;
        double ans = DBL_MAX, q_sum = 0;
       
        for(int i=0; i<quality.size(); i++) {
            ratio.push_back({(double)wage[i]/quality[i], i});
        }
        sort(ratio.begin(),ratio.end()); //sort wage to quality ratio in ascending order

         for(int i=0; i<wage.size(); i++) {
            int index = ratio[i].second;
            q_sum += quality[index]; //add quality of current worker
            pq.push({quality[index],index});

            if(pq.size() > k) { //do not store more than k workers in pq
                q_sum -= pq.top().first;
                pq.pop();
            }
        //total wage of k workers = (sum of quality) * (highest ratio)
            if(pq.size() == k) { 
                ans = min(ans,q_sum * ratio[i].first); //ratio is already sorted, so just multiply by current ratio
            }
        }
     return ans;
    }
};