#include <stdio.h>

struct Customer {
    int id;// ���
    char name[10];// ����
    int age;// ����
    char gender;// 'f'Ů ; 'm'��
    char phone[16];// �绰����
    char email[20];// ����
};

int customerNum = 0;// ��ǰ�ж��ٿͻ�
struct Customer customers[100];// �ͻ��ṹ������

int cmrLoop = 1;// �����Ƿ��˳�ѭ��

// *******************************************************************
// **************************** ���ݲ� ********************************
// *******************************************************************

// ���ҿͻ��Ƿ����
int findIndex(int id) {
    int index = -1;
    for (int i = 0; i < customerNum; ++i) {
        if (customers[i].id == id) {
            index = i;
        }
    }
    return index;
}

// ���ÿͻ�����
void setCustomerData(int index) {
    printf("\n����: ");
    scanf("%s", customers[index].name);
    getchar();
    printf("�Ա�: ");
    scanf("%c", &(customers[index]).gender);
    getchar();
    printf("����: ");
    scanf("%d", &(customers[index]).age);
    getchar();
    printf("�绰: ");
    scanf("%s", customers[index].phone);
    getchar();
    printf("����: ");
    scanf("%s", customers[index].email);
    getchar();
}

// ��ӿͻ�����
void addCustomerData() {
    customers[customerNum].id = customerNum + 1;
    setCustomerData(customerNum);
    customerNum++;
}

// �޸Ŀͻ�����
int updateCustomerData(int id) {
    int index = findIndex(id);
    if (index == -1) {
        return 0;
    } else {
        setCustomerData(index);
        return 1;
    }
}

// ��ȡ�ͻ�����
void getCustomerData(struct Customer *customer) {
    printf("\n%d\t%s\t%c\t%d\t%s\t%s", (*customer).id, (*customer).name, (*customer).gender, (*customer).age,
           (*customer).phone, (*customer).email);
}

// ɾ���ͻ�����
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
// **************************** ��ͼ�� ********************************
// *******************************************************************

// ��ʾ��ӿͻ�
void viewAdd() {
    printf("=============��ӿͻ�=============");
    addCustomerData();
    printf("=============������=============");
}

void viewUpdate() {
    int id = -1;
    printf("=============�޸Ŀͻ���Ϣ=============");
    printf("\n��ѡ����޸Ŀͻ����(-1�˳�):");
    scanf("%d", &id);
    getchar();
    if (id == -1) {
        printf("=============��������޸�=============");
        return;
    }
    printf("�Ƿ�ȷ���޸�(y/n): ");
    char isDel = 0;
    scanf("%c", &isDel);
    getchar();
    if (isDel == 'y') {
        if (updateCustomerData(id)) {
            printf("=============�޸ĳɹ�=============");
        } else {
            printf("=============�޸�ʧ�ܣ�id������=============");
        }
    } else {
        printf("=============��������޸�=============");
        return;
    }
}

// ��ʾɾ���ͻ�
void viewDel() {
    int id = -1;
    printf("=============ɾ���ͻ�=============");
    printf("\n��ѡ���ɾ���ͻ����(-1�˳�):");
    scanf("%d", &id);
    getchar();
    if (id == -1) {
        printf("=============�������ɾ��=============");
        return;
    }
    printf("�Ƿ�ȷ��ɾ��(y/n): ");
    char isDel = 0;
    scanf("%c", &isDel);
    getchar();
    if (isDel == 'y') {
        if (delCustomerData(id)) {
            printf("=============ɾ���ɹ�=============");
        } else {
            printf("=============ɾ��ʧ�ܣ�id������=============");
        }
    } else {
        printf("=============�������ɾ��=============");
        return;
    }
}

// ��ʾ�ͻ��б�
void viewCustomerList() {
    printf("=============�ͻ��б�=============");
    printf("\n���\t����\t�Ա�\t����\t�绰\t����");
    for (int i = 0; i < customerNum; ++i) {
        getCustomerData(&customers[i]);
    }
}

// ��ʾ�˳���ʾ
void viewCmrQuit() {
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
        cmrLoop = 0;
    }
}

// *******************************************************************
// **************************** ��ʾ�˵� ******************************
// *******************************************************************

void c1Menu(struct Customer *customer) {
    char key = 0;
    while (cmrLoop) {
        printf("\n================�ͻ�����ϵͳ================");
        printf("\n\t\t1 ��ӿͻ�");
        printf("\n\t\t2 �޸Ŀͻ�");
        printf("\n\t\t3 ɾ���ͻ�");
        printf("\n\t\t4 �ͻ��б�");
        printf("\n\t\t5 ��   ��");
        printf("\n��ѡ��(1-5): ");
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
                printf("δָ֪��");
                break;
        }
    }
    printf("�˳��ͻ�����ϵͳ");
}

void c1() {
    struct Customer customer;

    c1Menu(&customer);
}