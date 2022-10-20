#include <stdio.h>


void input(char a[]){
        printf("Nhap a: ");
        scanf("%s",a);
    
}

int isValid(char a[]){
    int b[100] = {0};
    for(int i = 0; a[i+1] != '\0'; i ++){
        if(b[i] == 0){
            if(a[i] == '{'){
                for(int j = i+1 ; a[j] != '\0'; j++){
                    if(a[j] == '}'){
                        b[i] = 1;
                        b[j] = 1;
                    }
                }
            }else if(a[i] == '['){
                for(int j = i+1 ; a[j] != '\0'; j++){
                    if(a[j] == ']'){
                        b[i] = 1;
                        b[j] = 1;
                    }
                }
            }else if(a[i] == '('){
                for(int j = i+1 ; a[j] != '\0'; j++){
                    if(a[j] == ')'){
                        b[i] = 1;
                        b[j] = 1;
                    }
                }
            }else{
                return 0;
            }
        }
    }
    for(int i = 0; a[i] != '\0'; i++){
        if(b[i] == 0){
            return 0;
        }
    }

    return 1;

}

int main(){
    char a[100];
    input(a);
    if(isValid(a)){
        printf("TRUE\n");
    }else{
        printf("False\n");
    }

    return 0;
}