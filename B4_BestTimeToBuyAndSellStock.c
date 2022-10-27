#include <stdio.h>

int IsSorted(int a[],int n){
    int x = 0;
    if(a[0] >= a[1]){
        for(int i = 1; i< n-1; i++){
            if(a[i] < a[i+1])
            return 0;
        }
        x = 1;
    }else if(a[0] < a[1]){
        for(int i = 1; i< n-1; i++){
            if(a[i]> a[i+1])
            return 0;
        }
        x = -1;
    }
    return x;
}
int Profit(int a[],int n){
    if(IsSorted(a,n) == 1){
        return 0;
    }else if(IsSorted(a,n) == -1){
        return a[n-1] - a[0];
    }else{
        int bD;
        int sD;
        int maxProfit = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(a[j] - a[i] > maxProfit){
                    bD = i;
                    sD = j;
                    maxProfit = a[sD] - a[bD];
                }
            }
        }
        return a[sD] - a[bD];
    }
}

int main(){
    int arr[100];
    int n;
    printf("Nhap so luong phan tu: \n");
    scanf("%d",&n);
    for(int i = 0; i< n; i++){
        printf("Nhap a[%d]: \n",i);
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i< n; i++){
        printf("%d ",arr[i]);
    }
    printf("/n");
    printf("Max profit is: %d",Profit(arr,n));
    return 0;
}