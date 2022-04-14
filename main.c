#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "manager.h"
#define _CRT_SECURE_NO_WARNINGS

int checkNation(){

    int check;
    printf("당신의 국적은?(내국인: 0, 외국인: 1) ");
    scanf("%d", &check);
    
    return check;
}
void printMode(int nation){
    if(nation==0){
        printf("==> 디버그 모드\n");
    }
    else{
        printf("==> debug mode\n");
    }
}

int selectMenu(){

    #ifdef DEBUG
        int nationCheck;
        nationCheck  = checkNation();
        printMode(nationCheck);
    #endif
    int menu;
    printf("\n*** 상점 ***\n");
    printf("1. 리스트 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 제품검색\n");
    printf("7. 제품조회\n");
    printf("8. 금액 이내 상품 보기\n");
    printf("9. 배송방법 확인\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    
    return menu;
}

int main(void){
    Product s[20];
    int menu;
    loadFile(s);

    while (1){

        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){listProduct(s);}
        else if (menu == 2){if(createProduct(s)==1){
            printf("=> 추가됨!\n");
        }}
        else if (menu == 3){if(updateProduct(s)==1){
            printf("=> 수정됨!\n");
        }}
        else if (menu == 4){if(deleteProduct(s)==1){
            printf("=> 삭제됨!\n");
        }}
        else if (menu == 5){if(saveFile(s)){
            printf("저장됨!\n");
        }}
        else if (menu == 6){
            searchProduct(s);
        }
        else if(menu==7){
            printProduct(s);
        }
        else if(menu==8){
            limitPrice(s);
        }
        else if(menu==9){
            checkDeliveryMethod(s);
        }
                
    }
    printf("종료됨!\n");
    return 0;
}