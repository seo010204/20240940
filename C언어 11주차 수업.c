#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct porduct
{
    char name[256];
    int receive;
    int price;
    int sale;
}PRODUCT;

int main()
{
    int receive, sale;
    int sum_sale;
    int proportion = 0;
    int sum_receive = 0;
    int most = 0;
    int min = 0;
    int id = 0;
    int select_menu = 0;
    int select_2 = 0;
    int type = 5;
    PRODUCT product[5] = { 0 };

    printf("[쇼핑몰 관리 프로그램]\n");
    printf(">원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체 현황, 5. 상품정보저장, 6. 상품정보가져오기, 7. 종료)\n");
    scanf_s("%d", &select_menu);
    while (select_menu != 7)
    {
        if (select_menu == 1)
        {
            printf("입고메뉴실행(상품 갯수 초과 시 메시지 출력)\n");
            printf("상품ID : ");
            scanf("%d", &id);
            printf("기존상품이 있으면 업데이트, 없으면 생성\n");
            printf("상품명 : ");
            scanf("%s", product[id - 1].name);
            printf("입고량 : ");
            scanf("%d", &product[id - 1].receive);
            printf("판매가격 : ");
            scanf("%d", &product[id - 1].price);
        }
        if (select_menu == 2)
        {
            printf("판매메뉴실행\n");
            printf("상품ID : ");
            scanf("%d", &id);
            printf("판매량 : ");
            scanf("%d", &product[id - 1].sale);
        }
        if (select_menu == 3)
        {
            printf("상품 ID를 입력하시오 : ");
            scanf("%d", &id);
            printf("상품명 : %s\n", product[id - 1].name);
            printf("입고량 : %d\n", product[id - 1].receive);
            printf("판매량 : %d\n", product[id - 1].sale);
            printf("판매가격 : %d\n", product[id - 1].price);
        }
        if (select_menu == 4)
        {
            sum_receive = 0;
            sum_sale = 0;
            printf("재고 수량 = > ");
            for (int k = 0; k < type; k++)
            {
                printf("%d ", product[k].receive - product[k].sale);
            }
            printf("\n총 판매량: ");
            for (int i = 0; i < type; i++)
            {
                sum_sale += product[i].sale;
                sum_receive += product[i].receive;
            }
            printf("%d (판매율 %.2lf%%)\n", sum_sale, ((double)sum_sale / sum_receive) * 100);
            printf("가장 많이 판매된 상품: ID ");
            for (int i = 0; i < type; i++)
            {
                if (most < product[i].sale)
                {
                    most = product[i].sale;
                    id = i + 1;
                }
            }
            printf("%d, 판매량 %d\n", id, most);
            printf("가장 적게 판매된 상품: ID ");
            min = product[0].sale;
            id = 1; 
            for (int i = 0; i < type; i++)
            {
                if (min > product[i].sale)
                {
                    min = product[i].sale;
                    id = i + 1;
                }
            }
            printf("%d, 판매량 %d\n", id, min);
        }
        if (select_menu == 5)
        {
            FILE* fp;
            if ((fp = fopen("product.bin", "wb")) == NULL) exit(1);
            fwrite(product, sizeof(PRODUCT), 5, fp);
            fclose(fp);
        }
        if (select_menu == 6)
        {
            FILE* fp;
            if ((fp = fopen("product.bin", "rb")) == NULL) exit(1);
            fread(product, sizeof(PRODUCT), 5, fp);
         
            fclose(fp); 
        }



        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 상품정보저장, 6. 상품정보가져오기, 7. 종료)\n");
        scanf("%d", &select_menu);
    }
    printf("프로그램을 종료합니다.\n");

    return 0;
}