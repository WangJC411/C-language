#include <stdio.h>
#include <stdlib.h>

int main()
{

//switch
//switch 支持嵌套
//switch 匹配成功則進入case之中，直到遇到break或者全部剩餘全部case執行完畢
    int day=0;
    printf("input the day:");
    scanf("%d",&day);
    switch(day)//判斷day是從哪裡進入的，day的值就相當於進入的鑰匙，如果對應的case進入後沒有break，則會繼續往下走。
    {
    case 1:
        printf("週一\n");
        break;

    case 2:
        printf("週二\n");
        break;

    case 3:
        printf("週三\n");
        break;

    case 4:
        printf("週四\n");
        break;

    case 5:
        printf("週五\n");
        break;

    case 6:
        printf("週六\n");
        break;

    default:
        printf("周日\n");
        break;
    }




    int n =1,m=0;
    switch(n)
    {
    case 1:// n = 1，匹配成功
        m++;   //沒有break，所以繼續往下 n=1,m=1
    case 2:
        n++;
        m++;  //沒有break，所以繼續往下  n=2,m=2
    case 3:
        switch(m)  //switch 的嵌套
        {
        case 1:   //m = 2 匹配失敗
            n++;
        case 2:   //m = 2 匹配成功
            n++;
            m++;  //沒有break，所以繼續往下  n = 3,m = 3
        case 3:
            m++;  //遇到break，不繼續往下，跳出switch  n = 3,m = 4
            break;
        case 4:
            m+=2;
            break;
        }
    case 4:
        m++;  //遇到break，不繼續往下，跳出switch  n = 3 , m= 5
        break;
    case 5:
        n++;
        break;

    }
printf("n=%d,m=%d\n",n,m);




    return 0;
}
