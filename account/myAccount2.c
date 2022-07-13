#include <stdio.h>
#include <string.h>


int loop = 1;
char tmp[100] = "";// 格式化每次的收入支出，并拼接到details

struct myFamilyAccount {
    char details[3000];// 明细
    double money;// 收入支出的金额
    char note[30];// 收入支出的说明
    double balance;// 余额
    char flag; // 判断当前是否有收入
};

void showDetails(struct myFamilyAccount *myFamilyAccount) {
    printf("================收支明细================\n");
    if ((*myFamilyAccount).flag) {
        printf("当前没有收支明细");
        return;
    }
    printf("收支\t收支金额\t账户余额\t说明");
    printf((*myFamilyAccount).details);
}

void income(struct myFamilyAccount *myFamilyAccount) {
    printf("================登记收入================\n");
    printf("本次收入金额: ");
    scanf("%lf", &(*myFamilyAccount).money);
    getchar();
    (*myFamilyAccount).balance += (*myFamilyAccount).money;
    printf("本次收入说明: ");
    scanf("%s", (*myFamilyAccount).note);
    getchar();
    sprintf(tmp, "\n收入\t%.2f\t\t%.2f\t\t%s", (*myFamilyAccount).money, (*myFamilyAccount).balance,
            (*myFamilyAccount).note);
    strcat((*myFamilyAccount).details, tmp);
    (*myFamilyAccount).flag = 0;
}

void pay(struct myFamilyAccount *myFamilyAccount) {
    printf("================登记支出================\n");
    printf("本次支出金额: ");
    scanf("%lf", &(*myFamilyAccount).money);
    getchar();
    // 判断余额是否足够
    if ((*myFamilyAccount).money > (*myFamilyAccount).balance) {
        printf("\n 余额不足");
        return;
    }
    (*myFamilyAccount).balance -= (*myFamilyAccount).money;
    printf("本次支出说明: ");
    scanf("%s", (*myFamilyAccount).note);
    getchar();
    sprintf(tmp, "\n支出\t%.2f\t\t%.2f\t\t%s", (*myFamilyAccount).money, (*myFamilyAccount).balance,
            (*myFamilyAccount).note);
    strcat((*myFamilyAccount).details, tmp);
    (*myFamilyAccount).flag = 0;
}

void quit() {
    char isExit = 0;// 接收 y/n 确认是否退出
    printf("是否确认退出(y/n)");
    while (1) {
        scanf("%c", &isExit);
        getchar();
        if (isExit == 'y' || isExit == 'n') {
            break;
        }
        printf("输入有误,请重新输入(y/n)");
    }
    if (isExit == 'y') {
        loop = 0;
    }
}

void a2Menu(struct myFamilyAccount *myFamilyAccount) {
    char key = 0;
    while (loop) {
        printf("\n================收支记账软件================");
        printf("\n\t\t1 收支明细");
        printf("\n\t\t2 登记收入");
        printf("\n\t\t3 登记支出");
        printf("\n\t\t4 退   出");
        printf("\n请选择(1-4): ");
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
                printf("\n未知的指令");
                break;
        }
    }
}

int a2() {
    struct myFamilyAccount myFamilyAccount;

    a2Menu(&myFamilyAccount);
}