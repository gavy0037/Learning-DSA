#include<iostream>
#include<vector>
#include<string>
using namespace std ;

string addBinary(string& s1, string& s2) {
        // your code here
        if(s1.length()!=s2.length()){//to make the lengths equal
            if(s1.length()<s2.length()){
                int n = s2.length()-s1.length();
                string a ;
                for(int i = 0 ; i < n ; i++){
                    a+='0';
                }
                a+=s1;
                s1 = a;
            }else{
                int n = s1.length()-s2.length();
                string a;
                for(int i = 0 ; i < n ; i++){
                    a+='0';
                }
                a+=s2;
                s2 = a;
            }
        }
        int n = s1.length();
        vector<char>ans(n+1,'0') ;
        int z = 0;
        int idx = n ;
        for(int i = s1.length()-1 ; i>=0 ; i--){
            int sum = (s1[i]-'0')^(s2[i]-'0')^z;
            ans[idx--] = sum +'0' ;
            z = (z&((s1[i]-'0')^(s2[i]-'0'))) | ((s1[i]-'0')&(s2[i]-'0'));
        }
        if(z!=0){
            ans[0] = '1';
        }
        // cout<<ans[0]<<endl;
        // ans[0]='1';//remove this
        int begin = 0 ;
        for(int i = 0 ; i < ans.size() ; i++){
            if(ans[i] == '1'){
                begin = i ;
                break;
            }
        }
        if(begin == ans.size()-1){
            return "0";
        }

        string s;
        for(int i = begin ; i < ans.size() ; i++){
            s+=ans[i];
        }

        return s ;
    }
int main(){
    string a = "01001001",b ="0110101";
    string ans = addBinary(a,b);
    cout<<ans<<endl;
    return 0 ;
}