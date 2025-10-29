/*
    The Stock Span Problem is a financial problem that requires calculating a value, called the "span," 
    for a series of daily stock price quotes.
    Problem Statement
    Given a sequence of N daily stock prices, P1, P2, P3 .... Pn, the goal is to compute the span for the price on each day i.
    The span (Si) of the stock price on a given day i is defined as:
    The maximum number of consecutive days immediately preceding the current day (i), including the current day itself,
    for which the stock price was less than or equal to the price on day i.In simpler terms, for the price today, 
    you count how many days you can look back (including today) until you find a day where the price was strictly greater than today's price.
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std ;

vector<int> stock_span(vector<int> nums){
    vector<int>ans ;
    for(int i = 0 ; i < nums.size() ; i++){
        int a = 0 ;
        for(int j = i ; j >= 0 ; j--){
            if(nums[j] <= nums[i]){
                a++;
            }else{
                break ;
            }
        }
        ans.push_back(a);
    }

    return ans; 
}

int main(){
    vector<int>nums = stock_span({30, 20, 10, 20, 30, 40});

    for(int i = 0 ; i < nums.size() ; i++){
        cout<<nums[i]<<' ';
    }

    return 0 ;
}