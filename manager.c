#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "manager.h"
#define _CRT_SECURE_NO_WARNINGS

int num=-1; // 현재 있는 곳의 인덱스
 
bool createProduct(Product s[20]); // 제품을 추가하는 함수, p는 제품 구조체들을 담은 배열
bool printProduct(Product s[20]); // 함수에서 출력할 하나의 제품을 묻고, 하나의 제품을 출력하는 함수
bool listProduct(Product s[20]); // 등록된 전체 제품 목록 출력
bool updateProduct(Product s[20]); // 등록된 제품 제품을 수정
bool deleteProduct(Product s[20]); // 제품 제품을 삭제
bool saveFile(Product s[20]); // 파일에 저장
void loadFile(Product s[20]); // 파일을 로드해서 데이터를 p에 저장, 갯수는 전역변수 num에 반영
void searchProduct(Product s[20]); // 함수에서 제품 이름을 묻고, 제품 이름을 검색
void limitPrice(Product s[20]); // 함수에서 가격 두개를 입력 받고, 두 가격 사이의 제품들 검색
void checkDeliveryMethod(Product s[20]); // 배송 방법에 따른 제품 검색


bool createProduct(Product s[20]){

    num++;
    getchar();
    printf("이름은? ");
    scanf("%[^\n]s", s[num].name);
    getchar();
    printf("설명은? ");
    scanf("%[^\n]s", s[num].description);
    getchar();
    printf("무게는? ");
    scanf("%[^\n]s", s[num].weight);
    printf("가격은? ");
    scanf("%d", &s[num].price);
    printf("배송 방법은? ");
    scanf("%d", &s[num].deliveryMethod);
    
    return true;
}

bool printProduct(Product s[20]){
    int printNum;
    printf("확인할 제품 번호는? ");
    scanf("%d", &printNum);
    printNum--;
    printf("================================\n");    
    printf("제품명: %s\n", s[printNum].name);
    printf("설명: %s\n", s[printNum].description);
    printf("중량: %s\n", s[printNum].weight);
    printf("가격: %d\n", s[printNum].price);
    printf("배송 방법: %d\n", s[printNum].deliveryMethod);
    printf("================================\n");

    return true;
}

bool listProduct(Product s[20]){
    printf("\nNo Name  Description  Weight  Price  DeliveryMethod\n");
    printf("================================\n");
    for(int i=0;i<=num;i++){
        if(strcmp(s[i].name,"")==0) 
            continue;
        printf("%d %s %s %s %d %d\n", i+1, s[i].name, s[i].description, s[i].weight, s[i].price, s[i].deliveryMethod);
    }
    printf("\n");
    return true;
}

bool updateProduct(Product s[20]){
    listProduct(s);
    int update_num;
    printf("번호는 (취소 :0)? ");
    scanf("%d", &update_num);
    if(update_num==0){
        printf("수정 취소!\n");
        return 0;
    }
    
    update_num--;
    getchar();
    printf("이름은? ");
    scanf("%[^\n]s", s[update_num].name);
    getchar();
    printf("설명은? ");
    scanf("%[^\n]s", s[update_num].description);
    getchar();
    printf("무게는? ");
    scanf("%[^\n]s", s[update_num].weight);
    printf("가격은? ");
    scanf("%d", &s[update_num].price);
    printf("배송 방법은? ");
    scanf("%d", &s[update_num].deliveryMethod);

    return true;
}

bool deleteProduct(Product s[20]){
    listProduct(s);
    int del_num, check;
    printf("번호는 (취소 :0)? ");
    scanf("%d", &del_num);
    if(del_num==0){
        printf("삭제취소!\n");
        return 0;
    }
    printf("정말로 삭제하시겠습니까?(삭제 :1) ");
    scanf("%d", &check);
    if(check!=1){
        printf("삭제취소!\n");
        return 0;
    }

    strcpy(s[del_num-1].name, "");

    return true;
}

bool saveFile(Product s[20]){

    FILE *fp=fopen("product.txt", "w");
    for(int i=0;i<=num;i++){
        if(strcmp(s[i].name, "")==0) continue;
        fprintf(fp, "%s %s %s %d %d\n", s[i].name, s[i].description, s[i].weight, s[i].price, s[i].deliveryMethod);
    }
    fclose(fp);
    return 1;
}

void loadFile(Product s[20]){
    FILE *fp = fopen("product.txt", "r+");
    if(fp==NULL){
        printf("=> 파일 없음\n");
    }
    else{
        while(feof(fp)==0){
        num++;
        fscanf(fp, "%s %s %s %d %d", s[num].name, s[num].description, s[num].weight, &s[num].price, &s[num].deliveryMethod);
        }
        fclose(fp);
        printf("==> 로딩 성공!\n");
    }
    
}

void searchProduct(Product s[20]){

    char searchName[20];
    int searchCheck=0;
    listProduct(s);	
    getchar();
    printf("검색할 이름은? ");
    scanf("%[^\n]s", searchName);
    getchar();
    printf("\nNo Name  Description  Weight  Price  DeliveryMethod\n");
    printf("================================\n");
    for(int i=0;i<=num;i++){
        if(strcmp(s[i].name,"")==0) continue;
        if(strstr(s[i].name, searchName)!=NULL){
            printf("%d %s %s %s %d %d\n", i+1, s[i].name, s[i].description, s[i].weight, s[i].price, s[i].deliveryMethod);
            searchCheck++;
        }
    }
    if(searchCheck==0){
        printf("==> 검색된 데이터 없음!\n");
    }

}

void limitPrice(Product s[20]){

    int minPrice, maxPrice, searchCheck=0;
    listProduct(s);    
    printf("최소 금액과 최대 금액은? ");
    scanf("%d %d", &minPrice, &maxPrice);
    printf("================================\n");    
    for(int i=0;i<=num;i++){
        if(strcmp(s[i].name,"")==0) continue;
        if(s[i].price >= minPrice && s[i].price <= maxPrice){
            printf("%d %s %s %s %d %d\n", i+1, s[i].name, s[i].description, s[i].weight, s[i].price, s[i].deliveryMethod);
            searchCheck++;
        }
    }
    if(searchCheck==0){
        printf("==> 검색된 데이터 없음!\n");
    }
    printf("================================\n");  
    

}

void checkDeliveryMethod(Product s[20]){

    int deliveryCheck, searchCheck=0;

    printf("원하는 배송방법은?(1:새벽배송, 2:택배배송) ");
    scanf("%d", &deliveryCheck);

    printf("================================\n");    
    for(int i=0;i<=num;i++){
        if(strcmp(s[i].name,"")==0) continue;
        if(deliveryCheck==s[i].deliveryMethod){
            printf("%d %s %s %s %d %d\n", i+1, s[i].name, s[i].description, s[i].weight, s[i].price, s[i].deliveryMethod);
            searchCheck++;
        }
    }
    if(searchCheck==0){
        printf("==> 검색된 데이터 없음!\n");
    }
    printf("================================\n");  

}
