#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std ;

    void fun(int n , int k , vector<int>& rem , string& ans , int fac){//rem contains numbers from 1 to n and has a size of n 
        int filled = n-rem.size();
        if(n == 1){
            ans.push_back(rem[0]+'0');
            rem.erase(rem.begin());
            return ;
        }
        if(rem.size() == 0){
            printf("hit\n");
            return ;
        }
        if(k <= fac){
            ans.push_back(rem[0]+'0');
            rem.erase(rem.begin());
            fun(n-1, k , rem , ans , fac/(n-filled-1));
        }
        for(int i = 1 ; i < n ; i++){
            if(i*fac< k && k <= (i+1)*fac){
                ans.push_back(rem[i]+'0');
                rem.erase(rem.begin()+i);
                fun(n-1 , k - i*fac , rem , ans , fac/(n-filled-1) );
            }
        }
    }

int main(){
    int n , k ;
    cin>>n>>k ;
    vector<int>rem(n) ;
    for(int i =0 ; i < n ; i++){
        rem[i] = i+1 ;
    }
    string ans ;
    int fac = 1 ;
    for(int i = 1 ; i < n ; i++){
        fac*=i ;
    }

    fun(n , k , rem , ans , fac) ;
    cout<<ans ;
    return 0 ;
}