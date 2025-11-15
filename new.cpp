#include<iostream>
#include<vector>

using namespace std ;

//i will use prefix sum to get the number of ones in a range 
//

int numberOfSubstrings(string s) {
    int n = s.length();
    vector<int>prefix(n+1) ;
    prefix[0] = 0 ;
    for(int i = 1 ; i <= n ;i++){
        prefix[i] = prefix[i-1] + s[i-1] -'0';
    }
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){   
            if(i == j){
                if(s[i] == '1'){
                    ans++;
                    //cout<<i<<' '<<j<<endl ;
                }
                continue ;
            }
            int ones = prefix[j+1]-prefix[i];
            int zeros = (j-i+1) - ones ;
            if(ones >= zeros*zeros){
                //cout<<i<<' '<<j<<endl ;
                ans++;
            }
        }
    }
    return ans ;
}

int main(){
    cout<<numberOfSubstrings("0110");
}