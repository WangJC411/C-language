#include <stdio.h>
#include <stdlib.h>

int main()
{

//switch
//switch ֧��Ƕ��
//switch ƥ��ɹ��t�M��case֮�У�ֱ������break����ȫ��ʣ�Nȫ��case�����ꮅ
    int day=0;
    printf("input the day:");
    scanf("%d",&day);
    switch(day)//�Д�day�Ǐ����e�M��ģ�day��ֵ���ஔ��M���耳ף����������case�M����]��break���t���^�m�����ߡ�
    {
    case 1:
        printf("�Lһ\n");
        break;

    case 2:
        printf("�L��\n");
        break;

    case 3:
        printf("�L��\n");
        break;

    case 4:
        printf("�L��\n");
        break;

    case 5:
        printf("�L��\n");
        break;

    case 6:
        printf("�L��\n");
        break;

    default:
        printf("����\n");
        break;
    }




    int n =1,m=0;
    switch(n)
    {
    case 1:// n = 1��ƥ��ɹ�
        m++;   //�]��break�������^�m���� n=1,m=1
    case 2:
        n++;
        m++;  //�]��break�������^�m����  n=2,m=2
    case 3:
        switch(m)  //switch ��Ƕ��
        {
        case 1:   //m = 2 ƥ��ʧ��
            n++;
        case 2:   //m = 2 ƥ��ɹ�
            n++;
            m++;  //�]��break�������^�m����  n = 3,m = 3
        case 3:
            m++;  //����break�����^�m���£�����switch  n = 3,m = 4
            break;
        case 4:
            m+=2;
            break;
        }
    case 4:
        m++;  //����break�����^�m���£�����switch  n = 3 , m= 5
        break;
    case 5:
        n++;
        break;

    }
printf("n=%d,m=%d\n",n,m);




    return 0;
}
