class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m= boxGrid[0].size();
        for(int i =0; i<n; i++){
            int first =0;
            for(int j =0; j<m; j++){
                if(boxGrid[i][j] == '.'){
                    swap(boxGrid[i][j], boxGrid[i][first]);
                    first++;
                }
                else if(boxGrid[i][j] == '*'){
                    first = j+1;
                }
            }
        }
        vector<vector<char>> rotated(m,vector<char> (n));
        for(int i =0;i<n; i++){
            for(int j =0; j<m; j++){
                rotated[j][n - 1- i] = boxGrid[i][j];
            }
        }
        return rotated;
    }
};