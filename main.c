#include <stdio.h>
#include <stdlib.h>

int main()
{
    //����getchar(),�õ�ݔ���ܴa��ĽY�����Q�з�֮��ĽY����
    // ch = getchar() ȡһ���ַ���ch�����յ�ch��������ͣ��ַ��DASCII��
    //putchar(ch); ��ch��ӡ����

    int ch;
    char password[20];
    printf("input a passwprd:");
    scanf("%s",&password);
    while (getchar() != '\n')   //ݔ����ܴa������ГQ�з����߿ո�֮��ַ���Ҫȥ��֮�ᣬ�����^�mݔ��Y/N
    {
        ; //�մ��a
    }
    printf("the password you input is %s\n",password);
    printf("check your password(Y/N):");
    ch = getchar();

    if(ch == 'Y')
    {
        printf("check successfully!\n");
    }
    else
    {
        printf("check fail!\n");
    }


// ����getchar()��ӡݔ����ַ�Ҫ�锵�֣���t����ӡ
    int ch1;
    while((ch1 = getchar()) != EOF)   //EOF��������ctrl+z������ֵ��-1
    {
        if(ch1<'0'||ch1>'9')   // Ҫ�á����A�����@�Ӳ����ַ�����ʽ���@߅������ACSII�a�ľ�̖��
        {
            continue;
        }
        else
        {
            putchar(ch1);
            printf("\n");
        }
    }


    return 0;
}
