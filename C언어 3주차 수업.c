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
	int select_4 = 0;
	int select_2 = 0;
	int type = 5;

	printf("[���θ� ���� ���α׷�]\n");
	printf(">���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ����)\n");
	scanf_s("%d", &select_4);
	while(select_4 != 4)
	{
		if (select_4 == 1)
		{
			printf("\n�԰���� �Է�: ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����\n");
			scanf_s("%d", &select_2);
			if (select_2 == 1)
			{
				printf("��ü ��ǰ�� �԰������ �Է�>>> ");
				for (int i = 0; i < 5; i++)
				{
					scanf_s("%d", &receive);
					total_receive[i] = receive;
				}
			}
			if (select_2 == 2)
			{
				printf("������ǰ ID �Է�\n");
				for (int i = 0; i < 5; i++)
				{
					printf("��ǰID : ");
					scanf_s("%d", &id);
					scanf_s("%d", &total_receive[id - 1]);
				}
			}
		}
		if (select_4 == 2)
		{
			printf("�Ǹż��� �Է� : ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����");
			scanf_s("%d", &select_2);
			if (select_2 == 1)
			{
				printf("��ü ��ǰ�� �Ǹż����� �Է�");
				for (int i = 0; i < 5; i++)
				{
					scanf_s("%d", &sale);
					total_sale[i] = sale;
				}
			}
			if (select_2 == 2)
			{
				printf("������ǰ ID �Է�\n");
				for (int i = 0; i < 5; i++)
				{
					printf("��ǰID : ");
					scanf_s("%d", &id);
					printf("�Ǹż��� : ");
					scanf_s("%d", &total_sale[id - 1]);
				}
			}
		}
		if (select_4 == 3)
		{
			sum_receive = 0;
			total = 0;
			printf("��� ���� = > ");
			for (int k = 0; k < type; k++)
			{
				printf("%d ", total_receive[k] - total_sale[k]);
			}
			printf("\n�� �Ǹŷ�: ");
			for (int i = 0; i < type; i++)
			{
				total += total_sale[i];
				sum_receive += total_receive[i];
			}
			printf("%d (�Ǹ��� %.2f%%)\n", total, ((double)total / sum_receive) * 100);
			printf("���� ���� �Ǹŵ� ��ǰ: ID ");
			for (int i = 0; i < type; i++)
			{
				if (most < total_sale[i])
				{
					most = total_sale[i];
					id = i + 1;
				}
			}
			printf("%d, �Ǹŷ� %d\n", id, most);
			printf("���� ���� �Ǹŵ� ��ǰ: ID ");
			min = total_sale[0];
			for (int i = 0; i < type; i++)
			{
				if (min > total_sale[i])
				{
					min = total_sale[i];
					id = i + 1;
				}
			}
			printf("%d, �Ǹŷ� %d\n", id, min);
			for (int i = 0; i < type; i++)
			{
				if (total_receive[i] - total_sale[i] <= 2)
				{
					printf("��ǰ ID %d: ������(%d)\n", i + 1, total_receive[i] - total_sale[i]);
				}
			}
		}
		printf(">���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ����)\n");
		scanf_s("%d", &select_4);
	}
	printf("���α׷��� �����մϴ�.\n");

	return 0;
}