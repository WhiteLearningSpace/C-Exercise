#include <stdio.h>
#include <string.h>


int loop = 1;
char tmp[100] = "";// ��ʽ��ÿ�ε�����֧������ƴ�ӵ�details

struct myFamilyAccount {
    char details[3000];// ��ϸ
    double money;// ����֧���Ľ��
    char note[30];// ����֧����˵��
    double balance;// ���
    char flag; // �жϵ�ǰ�Ƿ�������
};

void showDetails(struct myFamilyAccount *myFamilyAccount) {
    printf("================��֧��ϸ================\n");
    if ((*myFamilyAccount).flag) {
        printf("��ǰû����֧��ϸ");
        return;
    }
    printf("��֧\t��֧���\t�˻����\t˵��");
    printf((*myFamilyAccount).details);
}

void income(struct myFamilyAccount *myFamilyAccount) {
    printf("================�Ǽ�����================\n");
    printf("����������: ");
    scanf("%lf", &(*myFamilyAccount).money);
    getchar();
    (*myFamilyAccount).balance += (*myFamilyAccount).money;
    printf("��������˵��: ");
    scanf("%s", (*myFamilyAccount).note);
    getchar();
    sprintf(tmp, "\n����\t%.2f\t\t%.2f\t\t%s", (*myFamilyAccount).money, (*myFamilyAccount).balance,
            (*myFamilyAccount).note);
    strcat((*myFamilyAccount).details, tmp);
    (*myFamilyAccount).flag = 0;
}

void pay(struct myFamilyAccount *myFamilyAccount) {
    printf("================�Ǽ�֧��================\n");
    printf("����֧�����: ");
    scanf("%lf", &(*myFamilyAccount).money);
    getchar();
    // �ж�����Ƿ��㹻
    if ((*myFamilyAccount).money > (*myFamilyAccount).balance) {
        printf("\n ����");
        return;
    }
    (*myFamilyAccount).balance -= (*myFamilyAccount).money;
    printf("����֧��˵��: ");
    scanf("%s", (*myFamilyAccount).note);
    getchar();
    sprintf(tmp, "\n֧��\t%.2f\t\t%.2f\t\t%s", (*myFamilyAccount).money, (*myFamilyAccount).balance,
            (*myFamilyAccount).note);
    strcat((*myFamilyAccount).details, tmp);
    (*myFamilyAccount).flag = 0;
}

void quit() {
    char isExit = 0;// ���� y/n ȷ���Ƿ��˳�
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
}

void a2Menu(struct myFamilyAccount *myFamilyAccount) {
    char key = 0;
    while (loop) {
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
                showDetails(myFamilyAccount);
                break;
            case '2':
                income(myFamilyAccount);
                break;
            case '3':
                pay(myFamilyAccount);
                break;
            case '4':
                quit();
                break;
            default:
                printf("\nδ֪��ָ��");
                break;
        }
    }
}

int a2() {
    struct myFamilyAccount myFamilyAccount;

    a2Menu(&myFamilyAccount);
}