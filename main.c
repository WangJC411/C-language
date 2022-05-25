#include <stdio.h>
#include <stdlib.h>

int main()
{
    //利用getchar(),得到輸入密碼後的結果（換行符之後的結果）
    // ch = getchar() 取一個字符到ch，接收的ch是整數類型（字符轉ASCII）
    //putchar(ch); 把ch打印出來

    int ch;
    char password[20];
    printf("input a passwprd:");
    scanf("%s",&password);
    while (getchar() != '\n')   //輸入的密碼後面會有換行符或者空格之類的字符，要去掉之後，才能繼續輸入Y/N
    {
        ; //空代碼
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


// 利用getchar()打印輸入的字符要為數字，否則不打印
    int ch1;
    while((ch1 = getchar()) != EOF)   //EOF可以理解為ctrl+z，它的值為-1
    {
        if(ch1<'0'||ch1>'9')   // 要用‘’夾起來，這樣才是字符的形式（這邊的利用ACSII碼的編號）
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
