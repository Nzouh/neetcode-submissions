class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //this is a BFS problem

        queue<pair<int, int>> q; 
        int freshFruits = 0;
        vector<int> ud = {-1, 1, 0, 0};
        vector<int> lr = {0, 0, -1, 1};
        int nextCol = 0;
        int nextRow = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> seen(n, vector<int>(m, 0));
        int minute = 0;


        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = 2;
                }
                if(grid[i][j] == 1){
                    freshFruits++;
                }
            }
        }
        
        if(freshFruits == 0){
            return 0;
        }

        if(q.empty()){
            return -1;
        }
        

        while(!q.empty()){
            int bananaLayer = q.size();

            for(int i = 0; i < bananaLayer; i ++){
                auto [row, col] = q.front();
                q.pop();
                for(int d = 0; d < 4; d++){
                    nextCol = col + lr[d];
                    nextRow = row + ud[d];

                    if(nextCol >= 0 && nextCol < m && nextRow >= 0 && nextRow < n ){
                        if(grid[nextRow][nextCol] == 1){
                            grid[nextRow][nextCol] = 2;
                            q.push({nextRow, nextCol});
                            freshFruits--;

                            
                        }
                    }
                }
                
            }
            minute++;
            
        }

        if(freshFruits > 0){
            return -1;
        }

        return minute -1;
    }
};
