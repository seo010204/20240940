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
    int select_5 = 0;
    int select_2 = 0;
    int type = 5;
    PRODUCT product[5] = { 0 };

    printf("[���θ� ���� ���α׷�]\n");
    printf(">���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ������Ȳ, 4. ��ü ��Ȳ, 5. ����)\n");
    scanf_s("%d", &select_5);
    while (select_5 != 5)
    {
        if (select_5 == 1)
        {
            printf("�԰�޴�����(��ǰ ���� �ʰ� �� �޽��� ���)\n");
            printf("��ǰID : ");
            scanf_s("%d", &id);
            printf("������ǰ�� ������ ������Ʈ, ������ ����\n");
            printf("��ǰ�� : ");
            scanf_s("%s", product[id - 1].name, sizeof(product[id - 1].name));
            printf("�԰� : ");
            scanf_s("%d", &product[id - 1].receive);
            printf("�ǸŰ��� : ");
            scanf_s("%d", &product[id - 1].price);
        }
        if (select_5 == 2)
        {
            printf("�ǸŸ޴�����\n");
            printf("��ǰID : ");
            scanf_s("%d", &id);
            printf("�Ǹŷ� : ");
            scanf_s("%d", &product[id - 1].sale);
        }
        if (select_5 == 3)
        {
            printf("��ǰ ID�� �Է��Ͻÿ� : ");
            scanf_s("%d", &id);
            printf("��ǰ�� : %s\n", product[id - 1].name);
            printf("�԰� : %d\n", product[id - 1].receive);
            printf("�Ǹŷ� : %d\n", product[id - 1].sale);
            printf("�ǸŰ��� : %d\n", product[id - 1].price);
        }
        if (select_5 == 4)
        {
            sum_receive = 0;
            sum_sale = 0;
            printf("��� ���� = > ");
            for (int k = 0; k < type; k++)
            {
                printf("%d ", product[k].receive - product[k].sale);
            }
            printf("\n�� �Ǹŷ�: ");
            for (int i = 0; i < type; i++)
            {
                sum_sale += product[i].sale;
                sum_receive += product[i].receive;
            }
            printf("%d (�Ǹ��� %.2lf%%)\n", sum_sale, ((double)sum_sale / sum_receive) * 100);
            printf("���� ���� �Ǹŵ� ��ǰ: ID ");
            for (int i = 0; i < type; i++)
            {
                if (most < product[i].sale)
                {
                    most = product[i].sale;
                    id = i + 1;
                }
            }
            printf("%d, �Ǹŷ� %d\n", id, most);
            printf("���� ���� �Ǹŵ� ��ǰ: ID ");
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
            printf("%d, �Ǹŷ� %d\n", id, min);
        }   
        printf("���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ������Ȳ, 4. ��ü��Ȳ, 5. ����)\n");
        scanf_s("%d", &select_5);
    }
    printf("���α׷��� �����մϴ�.\n");

    return 0;
}
