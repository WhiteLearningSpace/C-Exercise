#include <stdio.h>
#include <string.h>

int a1() {
    char key = 0;
    int loop = 1;
    char isExit = 0;// ���� y/n ȷ���Ƿ��˳�
    char details[3000] = "";// ��ϸ
    char tmp[100] = "";// ��ʽ��ÿ�ε�����֧������ƴ�ӵ�details
    double money = 0000.00;// ����֧���Ľ��
    char note[30] = "";// ����֧����˵��
    double balance = 1000.0;// ���
    char flag = 1; // �жϵ�ǰ�Ƿ�������
    do {
        printf("\n================��֧�������================");
        printf("\n\t\t1 ��֧��ϸ");
        printf("\n\t\t2 �Ǽ�����");
        printf("\n\t\t3 �Ǽ�֧��");
        printf("\n\t\t4 ��   ��");
        printf("\n��ѡ��(1-4): ");
        scanf("%c", &key);
        getchar();
        switch (key) {
            case '1':
                printf("================��֧��ϸ================\n");
                if (flag) {
                    printf("��ǰû����֧��ϸ");
                    break;
                }
                printf("��֧\t��֧���\t�˻����\t˵��");
                printf(details);
                break;
            case '2':
                printf("================�Ǽ�����================\n");
                printf("����������: ");
                scanf("%lf", &money);
                getchar();
                balance += money;
                printf("��������˵��: ");
                scanf("%s", note);
                getchar();
                sprintf(tmp, "\n����\t%.2f\t\t%.2f\t\t%s", money, balance, note);
                strcat(details, tmp);
                flag = 0;
                break;
            case '3':
                printf("================�Ǽ�֧��================\n");
                printf("����֧�����: ");
                scanf("%lf", &money);
                getchar();
                // �ж�����Ƿ��㹻
                if (money > balance) {
                    printf("\n ����");
                    break;
                }
                balance -= money;
                printf("����֧��˵��: ");
                scanf("%s", note);
                getchar();
                sprintf(tmp, "\n֧��\t%.2f\t\t%.2f\t\t%s", money, balance, note);
                strcat(details, tmp);
                flag = 0;
                break;
            case '4':
                printf("�Ƿ�ȷ���˳�(y/n)");
                while (1) {
                    scanf("%c", &isExit);
                    getchar();
                    if (isExit == 'y' || isExit == 'n') {
                        break;
                    }
                    printf("��������,����������(y/n)");
                }
                if (isExit == 'y') {
                    loop = 0;
                }
                break;
            default:
                printf("\nδ֪��ָ��");
                break;
        }
    } while (loop);

    printf("\n================���˳�================");
    return 0;
}
