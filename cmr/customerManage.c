#include <stdio.h>

struct Customer {
    int id;// 编号
    char name[10];// 名称
    int age;// 年龄
    char gender;// 'f'女 ; 'm'男
    char phone[16];// 电话号码
    char email[20];// 邮箱
};

int customerNum = 0;// 当前有多少客户
struct Customer customers[100];// 客户结构体数组

int cmrLoop = 1;// 控制是否退出循环

// *******************************************************************
// **************************** 数据层 ********************************
// *******************************************************************

// 查找客户是否存在
int findIndex(int id) {
    int index = -1;
    for (int i = 0; i < customerNum; ++i) {
        if (customers[i].id == id) {
            index = i;
        }
    }
    return index;
}

// 设置客户数据
void setCustomerData(int index) {
    printf("\n姓名: ");
    scanf("%s", customers[index].name);
    getchar();
    printf("性别: ");
    scanf("%c", &(customers[index]).gender);
    getchar();
    printf("年龄: ");
    scanf("%d", &(customers[index]).age);
    getchar();
    printf("电话: ");
    scanf("%s", customers[index].phone);
    getchar();
    printf("邮箱: ");
    scanf("%s", customers[index].email);
    getchar();
}

// 添加客户数据
void addCustomerData() {
    customers[customerNum].id = customerNum + 1;
    setCustomerData(customerNum);
    customerNum++;
}

// 修改客户数据
int updateCustomerData(int id) {
    int index = findIndex(id);
    if (index == -1) {
        return 0;
    } else {
        setCustomerData(index);
        return 1;
    }
}

// 获取客户数据
void getCustomerData(struct Customer *customer) {
    printf("\n%d\t%s\t%c\t%d\t%s\t%s", (*customer).id, (*customer).name, (*customer).gender, (*customer).age,
           (*customer).phone, (*customer).email);
}

// 删除客户数据
int delCustomerData(int id) {
    int index = findIndex(id);
    if (index == -1) {
        return 0;
    } else {
        for (int i = index; i < customerNum; ++i) {
            customers[i] = customers[i + 1];
            customers[i].id--;
        }
        customerNum--;
        return 1;
    }
}

// *******************************************************************
// **************************** 视图层 ********************************
// *******************************************************************

// 显示添加客户
void viewAdd() {
    printf("=============添加客户=============");
    addCustomerData();
    printf("=============添加完成=============");
}

void viewUpdate() {
    int id = -1;
    printf("=============修改客户信息=============");
    printf("\n请选择待修改客户编号(-1退出):");
    scanf("%d", &id);
    getchar();
    if (id == -1) {
        printf("=============你放弃了修改=============");
        return;
    }
    printf("是否确认修改(y/n): ");
    char isDel = 0;
    scanf("%c", &isDel);
    getchar();
    if (isDel == 'y') {
        if (updateCustomerData(id)) {
            printf("=============修改成功=============");
        } else {
            printf("=============修改失败，id不存在=============");
        }
    } else {
        printf("=============你放弃了修改=============");
        return;
    }
}

// 显示删除客户
void viewDel() {
    int id = -1;
    printf("=============删除客户=============");
    printf("\n请选择待删除客户编号(-1退出):");
    scanf("%d", &id);
    getchar();
    if (id == -1) {
        printf("=============你放弃了删除=============");
        return;
    }
    printf("是否确认删除(y/n): ");
    char isDel = 0;
    scanf("%c", &isDel);
    getchar();
    if (isDel == 'y') {
        if (delCustomerData(id)) {
            printf("=============删除成功=============");
        } else {
            printf("=============删除失败，id不存在=============");
        }
    } else {
        printf("=============你放弃了删除=============");
        return;
    }
}

// 显示客户列表
void viewCustomerList() {
    printf("=============客户列表=============");
    printf("\n编号\t姓名\t性别\t年龄\t电话\t邮箱");
    for (int i = 0; i < customerNum; ++i) {
        getCustomerData(&customers[i]);
    }
}

// 显示退出提示
void viewCmrQuit() {
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
        cmrLoop = 0;
    }
}

// *******************************************************************
// **************************** 显示菜单 ******************************
// *******************************************************************

void c1Menu(struct Customer *customer) {
    char key = 0;
    while (cmrLoop) {
        printf("\n================客户管理系统================");
        printf("\n\t\t1 添加客户");
        printf("\n\t\t2 修改客户");
        printf("\n\t\t3 删除客户");
        printf("\n\t\t4 客户列表");
        printf("\n\t\t5 退   出");
        printf("\n请选择(1-5): ");
        scanf("%c", &key);
        getchar();
        switch (key) {
            case '1':
                viewAdd();
                break;
            case '2':
                viewUpdate();
                break;
            case '3':
                viewDel();
                break;
            case '4':
                viewCustomerList();
                break;
            case '5':
                viewCmrQuit();
                break;
            default:
                printf("未知指令");
                break;
        }
    }
    printf("退出客户管理系统");
}

void c1() {
    struct Customer customer;

    c1Menu(&customer);
}