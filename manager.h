typedef struct _Product{
    char name[20]; //제품명
    char description[100]; //제품 설명
    char weight[20]; // 제품 중량
    int price; // 제품 판매가격
    int deliveryMethod; // 배송방법(1:새벽배송, 2:택배배송)
}Product;

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
