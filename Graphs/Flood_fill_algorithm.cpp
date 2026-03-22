/*
You are given a 2D grid image[][], where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate (sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.
*/

#include<iostream>
#include<vector>
using namespace std ;

bool isvalid(int row , int col , int n , int m){
    return row >= 0 && col >= 0 && row < n && col < m ;
}

void dfs(vector<vector<int>> &img , int row , int col , int newColor , int ogColor , vector<int> &r , vector<int> &c){
    // An important edge case if newColor == ogColor
    int n = img.size() , m = img[0].size();
    img[row][col] = newColor ;
    for(int i = 0 ; i < 4 ; i++){
        int new_row = row + r[i] , new_col = col + c[i];
        if( isvalid(new_row , new_col , n , m) && img[new_row][new_col] == ogColor){
            dfs(img , new_row , new_col , newColor , ogColor , r , c);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {
    int ogColor = image[sr][sc];
    if(newColor == ogColor) return image;
    vector<int> r = {-1,0,1,0} , c = {0,1,0,-1};
    dfs(image , sr , sc , newColor , ogColor , r , c);

    return image ;
}