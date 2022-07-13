#include <stdio.h>
#include <string.h>

int a1() {
    char key = 0;
    int loop = 1;
    char isExit = 0;// 接收 y/n 确认是否退出
    char details[3000] = "";// 明细
    char tmp[100] = "";// 格式化每次的收入支出，并拼接到details
    double money = 0000.00;// 收入支出的金额
    char note[30] = "";// 收入支出的说明
    double balance = 1000.0;// 余额
    char flag = 1; // 判断当前是否有收入
    do {
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
                printf("================收支明细================\n");
                if (flag) {
                    printf("当前没有收支明细");
                    break;
                }
                printf("收支\t收支金额\t账户余额\t说明");
                printf(details);
                break;
            case '2':
                printf("================登记收入================\n");
                printf("本次收入金额: ");
                scanf("%lf", &money);
                getchar();
                balance += money;
                printf("本次收入说明: ");
                scanf("%s", note);
                getchar();
                sprintf(tmp, "\n收入\t%.2f\t\t%.2f\t\t%s", money, balance, note);
                strcat(details, tmp);
                flag = 0;
                break;
            case '3':
                printf("================登记支出================\n");
                printf("本次支出金额: ");
                scanf("%lf", &money);
                getchar();
                // 判断余额是否足够
                if (money > balance) {
                    printf("\n 余额不足");
                    break;
                }
                balance -= money;
                printf("本次支出说明: ");
                scanf("%s", note);
                getchar();
                sprintf(tmp, "\n支出\t%.2f\t\t%.2f\t\t%s", money, balance, note);
                strcat(details, tmp);
                flag = 0;
                break;
            case '4':
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
                break;
            default:
                printf("\n未知的指令");
                break;
        }
    } while (loop);

    printf("\n================已退出================");
    return 0;
}
