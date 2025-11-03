#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

  bool search(vector<int> &nums , int target){
        int st = 0 , end = nums.size()-1 ;
        while(st<= end){
            int mid = st +(end-st)/2 ;
            if(nums[mid] == target) return true ;
            else if(nums[mid] > target) end = mid-1 ;
            else st = mid+1 ;
        }
        return false ;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin() , nums.end());
        ListNode *newhead = NULL, *curr = head , *prev = NULL ;
        while(curr != NULL){
            if(newhead == NULL && !search(nums , curr->val)) newhead = curr ;
            if(search(nums , curr->val)){// if we find it then delete it
                if(newhead!= NULL ) prev->next = curr->next ;
            }else{
                prev = curr ;
            }
            curr = curr->next ;
        }
        return newhead ;
    }