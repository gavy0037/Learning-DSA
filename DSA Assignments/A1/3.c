    #include<stdio.h>
    #include<limits.h>

    int min(int a , int b){
        return a > b ? b : a ;
    }

    int main(){
        int t ;
        scanf("%d",&t);
        while(t--){
            int n ,k ;
            scanf("%d %d",&n , &k);
            int arr[n];
            for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
            // do modifications if sum too big (long will sufice)

            int sum = 0 , l = 0 , ans = INT_MAX;
            for(int r = 0 ; r < n ;r++){
                while(l < r && sum >= k){
                    sum-=arr[l++];
                    if(sum >= k){
                        ans = min(ans, r-l);
                        //printf("Equal case l:%d r:%d\n" , l , r);
                    }
                    while(l < r && arr[l] < 0){
                        sum-=arr[l++];
                        if(sum >= k){
                            ans = min(ans, r-l);
                            //printf("Equal case l:%d r:%d\n" , l , r);
                        }
                    }
                }
                sum+=arr[r];
                if(sum >= k){
                    ans = min(ans , r-l+1);
                    //printf("Greater than or equal case l:%d r:%d\n" , l , r);
                }
            }

            
            while(l < n && sum >= k){
                sum-=arr[l++];
                if(sum >= k){
                    ans = min(ans, n-l);
                    //printf("Equal case l:%d r:%d\n" , l , r);
                }
                while(l < n && arr[l] < 0){
                    sum-=arr[l++];
                    if(sum >= k){
                        ans = min(ans, n-l);
                        //printf("Equal case l:%d r:%d\n" , l , r);
                    }
                }
            }
            if(ans == INT_MAX) printf("-1\n");
            else printf("%d\n",ans);
        }

        return 0 ;
    }