#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std ;

void help(vector<int> &arr , vector<string>& ans ,string& temp, int pos , unordered_map<int,string>m , int a){
        if(temp.size() == a){
            ans.push_back(temp);
            return ;
        }
        
        for(int i = pos ; i < arr.size() ; i++){
            if(arr[i] == 1||arr[i] == 0) continue ;
            string curr = m[arr[i]];
            
            if(arr[i] == 7 || arr[i] == 9){
                for(int j = 0 ; j < 4  ; j++){
                    temp.push_back(curr[j]);
                    help(arr , ans , temp , i+1,m,a);
                    temp.pop_back();
                }
            }else{
                for(int j = 0 ; j < 3 ; j++){
                    temp.push_back(curr[j]);
                    help(arr , ans , temp , i+1,m,a);
                    temp.pop_back();
                }
            }
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        unordered_map<int,string>m ;
        m[2] = "abc";m[3] = "def";
        m[4] = "ghi";m[5] = "jkl";
        m[6] = "mno";m[7] = "pqrs";
        m[8] = "tuv"; m[9] = "wxyz";
        
        int a = 0 ;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] != 0 && arr[i] != 1){
                a++;
            }
        }
        
        vector<string>ans ;
        string temp ;
        help(arr , ans , temp , 0, m, a );
        return ans ;
    }