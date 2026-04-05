#include<bits/stdc++.h>

using namespace std ;

#define MOD 1000000007

bool check(vector<int> &nums1 , vector<int> &nums2 , int length){
    // first check if subarray of length of nums2 is in nums1

    // using rolling hash with sliding window

    long long pow = 1;
    unordered_set<int>s ;
    long long hash = 0 ;
    for(int i = length-1 ; i >=0 ; i--){
        hash = (hash+(long long)nums1[i]*pow)%MOD;
        pow*=31;
    }

    s.insert(hash);
    for(int i = length ; i < nums1.size() ; i++){
        hash = (hash-(long long)nums1[i-length]*pow)%MOD ;
        hash*=31;
        hash+=nums1[i];
        s.insert(hash);
    }
    hash = 0 ;
    pow = 1 ;
    for(int i = length-1 ; i >=0 ; i--){
        hash = (hash+(long long)nums2[i]*pow)%MOD;
        pow*=31;
    }

    if(s.find(hash) != s.end()) return true ;
    for(int i = length ; i < nums2.size() ; i++){
        hash = (hash-(long long)nums1[i-length]*pow)%MOD ;
        hash*=31;
        hash+=nums1[i];
        if(s.find(hash) != s.end()) return true ;
    }
    return false ;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n , m ;
    cin>>n>>m ;
    vector<int>nums1(n) , nums2(m);
    unordered_map<string , int> mp ; 
    int counter = 0 ;
    string s;
    for(int i = 0 ; i < n ; i++){
        cin>>s ;

        if(mp.find(s) == mp.end()){ // if this word is not in the current mapping
            mp[s] = counter ;
            counter++;
        }
        nums1[i] = mp[s];
    }

    for(int i = 0 ; i < m ; i++){
        cin>>s ;

        if(mp.find(s) == mp.end()){ // if this word is not in the current mapping
            mp[s] = counter ;
            counter++;
        }
        nums2[i] = mp[s];
    }

    int st = 1 , end = min(n,m) ;
    int ans = 0 ;
    while(st<=end){
        int mid = (st+end)/2;
        if(check(nums1 , nums2 , mid) || check(nums2 , nums1 , mid)){
            // check if a bigger common subarray exists
            ans = mid ;
            st = mid+1 ;
        }else{
            end = mid-1 ;
        }
    }
    cout<<ans<<endl ;

    return 0 ;
}