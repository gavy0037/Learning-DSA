#include<iostream>
#include<vector>
#include<map>

using namespace std ;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int> res;
    map<int , int> color_freq , ballColor_map;

    for(auto &v : queries){
        // if current ball is marked
        int ball = v[0] , color = v[1];
        if(ballColor_map.find(ball) != ballColor_map.end()){
            int prev_color = ballColor_map[ball] ;
            color_freq[prev_color]--;
            if(color_freq[prev_color] == 0) color_freq.erase(prev_color);
        }
        ballColor_map[ball] = color ;
        color_freq[color]++;
        res.push_back(color_freq.size());
    }
    return res ;
}