class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
       sort(properties.begin(), properties.end(), [](const vector<int>& x, const vector<int>& y) {
            
           if(x[0]==y[0])
           {
            return x[1]<y[1];
           }
           return x[0]>y[0];
        });
        
        int defense=0;
        int count=0;
        for(int i=0;i<properties.size();i++)
        {
          if(properties[i][1]<defense)
          {
            count++;
          }
          else 
          {
        
        defense=properties[i][1]; 
          }
        }
        return count;
    }
};