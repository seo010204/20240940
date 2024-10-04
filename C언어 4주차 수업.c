#include <stdio.h>

int main()
{
    int receive, sale;
    int total_receive[100];
    int total_sale[100];
    int total = 0;
    int proportion = 0;
    int sum_receive = 0;
    int most = 0;
    int min = 0;
    int id = 0;
    int select_5 = 0;
    int select_2 = 0;
    int type = 5;
    char name[5][256];

    printf("[쇼핑몰 관리 프로그램]\n");
    printf(">원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료)\n");
    scanf_s("%d", &select_5);
    while (select_5 != 5)
    {
        if (select_5 == 1)
        {
            printf("\n입고수량 입력: 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n");
            scanf_s("%d", &select_2);
            if (select_2 == 1)
            {
                printf("전체 상품의 입고수량을 입력>>> ");
                for (int i = 0; i < 5; i++)
                {
                    scanf_s("%d", &receive);
                    total_receive[i] = receive;
                }
            }
            if (select_2 == 2)
            {
                printf("개별상품 ID 입력\n");
                printf("상품ID : ");
                scanf_s("%d", &id);
                printf("입고수량: ");
                scanf_s("%d", &total_receive[id - 1]);
            }
        }
        if (select_5 == 2)
        {
            printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택");
            scanf_s("%d", &select_2);
            if (select_2 == 1)
            {
                printf("전체 상품의 판매수량을 입력");
                for (int i = 0; i < 5; i++)
                {
                    scanf_s("%d", &sale);
                    total_sale[i] = sale;
                }
            }
            if (select_2 == 2)
            {
                printf("개별상품 ID 입력\n");
                printf("상품ID : ");
                scanf_s("%d", &id);
                printf("판매수량 : ");
                scanf_s("%d", &total_sale[id - 1]);
            }
        }
        if (select_5 == 3)
        {
            sum_receive = 0;
            total = 0;
            printf("재고 수량 = > ");
            for (int k = 0; k < type; k++)
            {
                printf("%d ", total_receive[k] - total_sale[k]);
            }
            printf("\n총 판매량: ");
            for (int i = 0; i < type; i++)
            {
                total += total_sale[i];
                sum_receive += total_receive[i];
            }
            printf("%d (판매율 %.2f%%)\n", total, ((double)total / sum_receive) * 100);
            printf("가장 많이 판매된 상품: ID ");
            for (int i = 0; i < type; i++)
            {
                if (most < total_sale[i])
                {
                    most = total_sale[i];
                    id = i + 1;
                }
            }
            printf("%d, 판매량 %d\n", id, most);
            printf("가장 적게 판매된 상품: ID ");
            min = total_sale[0];
            for (int i = 0; i < type; i++)
            {
                if (min > total_sale[i])
                {
                    min = total_sale[i];
                    id = i + 1;
                }
            }
            printf("%d, 판매량 %d\n", id, min);
            for (int i = 0; i < type; i++)
            {
                if (total_receive[i] - total_sale[i] <= 2)
                {
                    printf("상품 ID %d : 상품명 : %s 재고부족(%d)\n", i + 1, name[i], total_receive[i] - total_sale[i]);
                }
            }
        }
        if (select_5 == 4)
        {
            printf("상품명입력 메뉴 실행 >> \n");
            for (int i = 0; i < type; i++)
            {
                printf("ID %d 상품명 : ", i + 1);
                scanf_s("%s", name[i], sizeof(name[i]) / sizeof(name[i][0]));
            }
        }
        printf(">원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력, 5. 종료)\n");
        scanf_s("%d", &select_5);
    }
    printf("프로그램을 종료합니다.\n");

    return 0;
}