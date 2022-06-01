#include <stdio.h>
#include <stdlib.h>

int main()
{


    //計算n的階乘

    int num=0;
    long long sum=1;
    printf("input a number:");
    scanf("%d",&num);
    for(int i = num; i>0; --i)
    {
        sum = sum * i;
    }
    printf("%d! = %d\n",num,sum);


//--------------------------------------------------------------------------


    //計算1!+2!+3!+4!+5!+6!+7!+8!+9!+10!
    int total = 1;
    sum = 0;

    //方法一：（比較容易想的方法）
    for(int j=1; j<=10; ++j)
    {
        total = 1; //需要在計算單個數的階乘之前要先初始化total，不然會在之前的total上相乘
        for(int i=j; i>0; --i)
        {

            total = total * i;
        }
        sum = total+sum;
    }
    printf("1!+2!+3!+4!+5!+6!+7!+8!+9!+10! = %d\n",sum);

    //方法二：（代碼比較簡潔的方法）
    total = 1;
    sum = 0;
    for(int i = 1; i<=10; ++i)
    {
        total = total * i;  //不改變total的結果，每次往上乘一個更高的數，就是下一個數的階乘
        sum = total + sum;
    }
    printf("1!+2!+3!+4!+5!+6!+7!+8!+9!+10! = %d\n",sum);

//---------------------------------------------------------------------------------

    //從一個有序的數組裡面找到想要的值

    //方法一：（比較好理解的方法）
    const int arr[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int target = 0,flag = 0;
    printf("input the number what you find:");
    scanf("%d",&target);

    const int size = sizeof(arr)/sizeof(arr[0]);  //sizeof是找變量的內存大小，數組總的內存大小除以單個數組的內存大小等於數組個數
    printf("size = %d\n",size);
    for(; flag<size; ++flag)
    {
        if(arr[flag] == target)
        {
            printf("找到數字%d，位置在%d\n",target,flag);
            break;
        }
    }
    if(flag == size)   //找不到的情況，因為如果最後都找不到，則flag一定會等於size
    {
        printf("沒有相對應的數字！\n");
    }


    //方法二（二分查找算法）從每個數組的中間開始找，然後按照大小再對半找,前提是數組是有序的
    flag = 0;
    int start = 0,end = size-1;
    flag = (end+start)/2;
    while(arr[flag] != target)
    {
        if(arr[flag] > target)
        {
            end = flag;
            flag = (end + start)/2;
        }
        else if(arr[flag] < target)
        {
            start = flag;
            flag = (end + start)/2+1; //+1是為了避免start=12,end=13時，一直死循環
        }
        if(start == end)
        {
            printf("沒有相對應的數字!\n");
            break;
        }

    }
    if(arr[flag] == target)
    {
        printf("找到數字%d，位置在%d\n",target,flag);
    }


//-------------------------------------------------------------------------

    //一開始是第二行字符串，然後開始顯示頭一和尾一，再是頭二和尾二，直到全部顯示完
    //QYZ wo bu xiang zai ai ni le !!!!!!!
    //************************************
    char target1[] = "QYZ wo bu xiang zai ai ni le !!!!!!!!!";
    char shield[] = "**************************************";
    int size1 = sizeof(target1)/sizeof(target1[0]);
    printf("size1 = %d\n",size1);
    end = size1 - 2;  //減2是因為字符串後面有一個\n，所以要額外多減一個
    start = 0;
    do
    {
        printf("shield = %s\n",shield);
        shield[start] = target1[start];
        shield[end] = target1[end];
        start++;
        end--;
    }
    while(start <= end+2);  //加2的目的是循環中是先賦值再++和--，所以當size1是even時，最中間的值不會被取代
    //////////////////////////但如果改成先++和--再賦值的話，第一個值和最後一個值就沒辦法被取代


//------------------------------------------------------------------------------------------------


    //  只能輸入三次密碼，如果三次失敗，則停止登錄
    //  " == " 不能比較兩個字符串是否相等，要用一個函數strcmp

    char password1[] = "123456789",password2[20]= {0}; //password2這種要輸入的字符串要先初始化一下
    for(int a=0; a<3; a++)
    {
        printf("input your password:");
        scanf("%s",&password2);
        if (strcmp(password1,password2) == 0)
        {
            printf("登錄成功！\n");
            break;
        }
        if(a == 2)
        {
            printf("登錄失敗！\n");
        }


    }


//----------------------------------------------------------
//找出100~200之間的素數
//
    int r=0,s=0,count = 0;
    for (r=100; r<=200; ++r)
    {
        for(s=2; s<r; ++s)
        {
            if(r%s == 0)
            {
                break;
            }

        }
        if(s == r)
        {
            printf("%d ",r);
            count++;

        }
    }

    printf("\ncount = %d\n",count);

//上面的代碼容易理解，但是還可以從數學方面進行優化
//例如：even不可能為素數，所以直接把r++改成r+=2，r從101出發
//s可以變成小於等於根號r，因為如果有公約數，一定是有一個小於等於根號r，一個大於等於根號r

    r = 0;
    s = 0;
    count = 0;
    for (r=101; r<=200; r+=2)
    {
        for(s=2; s<=sqrt(r); ++s)
        {
            if(r%s == 0)
            {
                break;
            }

        }
        if(s > sqrt(r))
        {
            printf("%d ",r);
            count++;

        }
    }

    printf("\ncount = %d\n",count);


    return 0;
}
