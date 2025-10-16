#include<iostream>
#include<vector>
#include<climits>
using namespace std;  

    int maxArea(vector<int>& height){
        int st = 0 , end = height.size() - 1 , area ,areamax = INT_MIN ;
        while(st < end){
            area = (end - st)*(min(height[st],height[end])) ;
            areamax = max(areamax,area);
            if (height[st] > height[end]){
                end--;
            }else{
                st++;
            }
        }
    return areamax;
    }


    //BRUTE FORCE APPROACH
    
    // int maxArea(vector<int>& height) {
    //     int area , areamax = INT_MIN ;
    //    for(int i = 0 ; i < height.size();i++){
    //     for(int j = i+1 ; j <height.size() ; j++ ){

    //         area = (min(height[i],height[j]))*(j-i);
    //         areamax = max(area,areamax);
    //     }
    //    } 
    //    return areamax;
    // }