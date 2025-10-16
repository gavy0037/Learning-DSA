#include<stdio.h>

void PrintAllSubsets(int n , int arr[] , int position , int temp[] , int SubsetSize){

    if(position == n){
        printf("{");
        for(int i = 0 ; i < SubsetSize ; i++){
            if(i == SubsetSize-1) printf("%d",temp[i]);
            else{
                printf("%d,",temp[i]);
            }
        }
        printf("}\n");
        return; 
    }

    PrintAllSubsets(n , arr , position +1 , temp ,SubsetSize) ;

    temp[SubsetSize] = arr[position];

    PrintAllSubsets(n , arr , position+1 , temp , SubsetSize+1);
}


void Print_Subsets_with_sum_k(int n, int arr[] , int position , int temp[] , int subset_size,int sum , int target){
    if(target == 0) {
        printf("{}\n");
        return; 
    }

    if(position == n ){
        if(sum!=target) return ;
        else{
            printf("{");
        for(int i = 0 ; i<subset_size ; i++){
            if(i == subset_size-1) printf("%d",temp[i]);
            else{
                printf("%d,",temp[i]);
            }
        }
        printf("}\n");
        return; 
        }
    }

    Print_Subsets_with_sum_k(n , arr , position +1 , temp , subset_size , sum,target);
    
    temp[subset_size] = arr[position];
    Print_Subsets_with_sum_k(n , arr , position +1, temp , subset_size +1,sum+arr[position] ,target);
}

void No_of_subsets_with_sum_k(int n, int arr[] , int position , int target,int *count){
    if(position == n){
        if(target == 0){
            (*count)++;
            return ;
        }else{
            return;
        }
    }

    No_of_subsets_with_sum_k(n , arr , position+1 , target , count);

    No_of_subsets_with_sum_k(n , arr , position+1 , target-arr[position], count);
}

void Print_k_sized_subsets(int n , int arr[] , int position , int temp[] , int subsetSize , int k){
    if(subsetSize == k){
        printf("{");
        for(int i = 0 ; i < k ; i++){
            if(i != k-1){
                printf("%d," , temp[i]);
            }else{
                printf("%d",temp[i]);
            }
        }
        printf("}\n");
        return ;
    }
    for(int i = position; i < n ; i++){
        //include the ones in front so postion becomes i+1
        temp[subsetSize] = arr[i];
        Print_k_sized_subsets(n , arr , i+1 , temp , subsetSize+1 , k);
    }
}

void Unique_subsets(int n , int arr[] , int temp[],int pos , int size){

        printf("{");
        for(int i = 0 ; i < size ;i++){
            if(i!= size-1 )printf("%d, ",temp[i]);
            else{
                printf("%d",temp[i]);
            }
        }
        printf("}\n");
 

    for(int i = pos ; i < n ; i++){
        if(i>pos && arr[i] == arr[i-1]) continue ;

//        subsets2(n , arr , temp , i+1 , size);

        temp[size] = arr[i];
        subsets2(n , arr , temp , i+1 , size+1);
    }
}

int main(){
    int n ,target;
    scanf("%d %d",&n,&target);
    int arr[n];
    for(int  i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    int temp[target] ;

    // int count = 0 ;
    // No_of_subsets_with_sum_k(n , arr , 0 ,target , &count) ;
    // printf("%d\n",count);

    //Print_Subsets_with_sum_k(n,arr,0,temp,0 , 0 , target);

    // Print_k_sized_subsets(n , arr , 0 , temp ,0 , target);

    return 0 ;
}