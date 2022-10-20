#include <stdio.h>
#include <stdlib.h>

void input(int *a,int n){
    for(int i = 0; i < n; i ++){
        printf("Nhap a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
void output(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = %d\n",i,a[i]);
    }
}

int *TwoSum(int a[],int n, int key){
    int *p = (int *)malloc(2*sizeof(int));
    for(int i = 0; i< n-1; i++){
        for(int j = i+1; j < n ; j++){
            if(a[i] == key - a[j] ){
                p[0] = i;
                p[1] = j;
                return p;
            }
        }
    }
}

int main(){
    int a[100];
    int n;
    int key;
    int *ans;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the key: \n");
    scanf("%d",&key);
    input(a,n);
    ans = TwoSum(a,n,key);
    printf("[%d %d]\n",a[ans[0]],a[ans[1]]);
    
    

    return 0;
}