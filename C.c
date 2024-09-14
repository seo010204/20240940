#include <stdio.h>

int main()
{
	int type, receive, sale, ID;
	int total_receive[100];
	int total_sale[100];

	printf("상품 개수(종류)입력 ");
	scanf_s("%d", &type);
	printf("상품 별 입고수량 입력 ");
	for (int i = 0; i < type; i++)
	{
		scanf_s("%d", &receive);
		total_receive[i] = receive;
	}
	printf("상품 별 판매수량 입력 ");
	for (int j = 0; j < type; j++)
	{
		scanf_s("%d", &sale);
		total_sale[j] = sale;
	}	
	printf("ID 입력 ");
	scanf_s("%d", &ID);
	printf("입력한 ID에 해당하는 제품의 재고 수량 => %d\n", total_receive[ID - 1] - total_sale[ID - 1]);
	printf("모든 상품의 재고 수량 출력 = > ");
	for (int k = 0; k < type; k++)
	{
		printf("%d ", total_receive[k] - total_sale[k]);
	}
	



	return 0;
}
