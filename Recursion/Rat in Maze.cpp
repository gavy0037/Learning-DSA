#include<iostream>
#include<vector>
#include<string>

using namespace std ;

    bool isvalid(int n , int r , int c , vector<vector<int>>& maze ){
        return r>=0 && c>=0 && r<n && c<n && maze[r][c];
    }

    void helper(vector<vector<int>>& maze,vector<string>&ans , string& temp , int row , int col , int n , char dir[] , int dr[],int dc[]){
        if(maze[row][col] == 0) return ;

        if(row == n-1 && col == n-1){
            ans.push_back(temp);
            return ;
        }

        maze[row][col] = 0 ;//mark as visited
        for(int i = 0 ; i < 4 ; i++){
            if(isvalid(n , row+ dr[i] , col+dc[i],maze)){
                temp.push_back(dir[i]);
                helper(maze , ans , temp , row+ dr[i] , col+dc[i] , n , dir , dr , dc);
                temp.pop_back();
            }
        }
        maze[row][col] = 1 ;//mark as unvisited
    }
        




    vector<string> ratInMaze(vector<vector<int>>& maze) {
            // code here
            char dir[5] = "UDLR" ;
            int dr[4] = {-1,1,0,0};
            int dc[4] = {0,0,-1,1};
            vector<string> ans;
            string temp ;
            helper(maze , ans , temp , 0 , 0 , maze.size() , dir , dr , dc);

            return ans ;
    }