#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int prime(int);
int search(int arr3[],int,int);
void print(int n);
int cal(char*);
int cal1(char* str);
int fib1(int n);
int fib2(int n);

int main()
{

// strcpy函數   字符串複製
// strcpy(arr1,arr2);  把arr2裡的字符串複製到arr1裡面去
    printf("---strcpy---\n");
    char arr1[20] = "qwertyui";
    char arr2[20] = "asdfghjk";
    printf("複製前：\narr1 = %s\narr2 = %s\n",arr1,arr2);
    strcpy(arr1,arr2);
    printf("複製後：\narr1 = %s\narr2 = %s\n",arr1,arr2);


// memset函數   設置內存前面的部分內容
// memset(arr1,'*',5);   把arr1前面5個字符改成*
    printf("---memset---\n");
    memset(arr1,'*',5);
    printf("arr1 = %s\n",arr1);


//自定義函數
//函數的調用
//傳值調用：函數的形參和實參分別找有不同的內存塊，對形參的修改不會影響實參
//傳址調用：把函數外部創建變量的內存地址傳遞給函數，這種傳參方式可以讓函數和函數外邊的變量建立起真正的聯繫，也就是函數內部直接可以操作函數外部的變量

//用函數來找100~200之間的素數

    int i = 0,count = 0;
    for(i=100; i<=200; ++i)
    {
        if(prime(i) == 1)
        {
            printf("%d ",i);
            count += 1;
        }
    }
    printf("\ncount = %d\n",count);


//用函數查找數組裡的指定數字（二分法）
    int arr3[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 0,size = 0,result = 0;
    size = sizeof(arr3)/sizeof(arr3[0]);
    printf("input a target:");
    scanf("%d",&target);
    result = search(arr3,target,size);
    if(result == -1)
    {
        printf("沒找到指定的數字\n");
    }
    else
    {
        printf("找到指定數字，下標為%d\n",result);
    }




//遞歸
//遞歸存在限制條件，當滿足這個限制條件的時候，遞歸便不再繼續
//每次遞歸調用之後越來越接近這個限制條件


//用函數的遞歸，把一個多位數按照順序一個一個輸出數字

    int num = 0;
    printf("input a number:");
    scanf("%d",&num);
    print(num);
    printf("\n");



//自己寫一個程式，擁有strlen的作用
    char str[20] = "asfgsgenrszsgthsgee";
    int len=0;
    len = cal(str);
    printf("len = %d\n",len);

//利用遞歸的方法
    len = cal1(str);
    printf("len = %d\n",len);




//斐波那契數列計算

//用遞歸的方式做的話超過45就會變得很沒有效率，所以這個不適合用遞歸的方法去做
    int n1;
    scanf("%d",&n1);
    int result2 = fib1(n1);
    printf("斐波那契數列result = %d\n",result2);

//用循環的方法去做速度會比較快

    result2 = fib2(n1);
    printf("菲波那切數列result = %d\n",result2);





    return 0;
}


//----------副程式-----------


int prime(int n)
{
    int a = 0;
    for(a = 2; a<=sqrt(n); ++a)
    {
        if(n%a==0)
        {
            break;
        }
    }
    if(a > sqrt(n))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int search(int arr3[],int target,int size)
{
    int flag = 0,start = 0,end = size-1 ;
    flag = (start + end)/2;

    while(start <= end)
    {
        if(arr3[flag]<target)
        {
            start = flag+1;
            flag = (start+end)/2;
        }
        else if(arr3[flag]>target)
        {
            end = flag-1;
            flag = (start+end)/2;
        }
        else
        {
            return flag;
        }

    }
    return -1;
}

void print(int n)
{
    if(n>9)
    {
        print(n/10);
        printf("%d ",n%10);
    }
    else
    {
        printf("%d ",n);
    }

}

int cal(char* str)  //字符串傳入的時候是傳入首字符的地址，所以要用char*接收
{
    int len = 0;
    while(*str != '\0')   // 判斷*str第一個字母是不是結束符
    {
        len++;
        str++;   //地址+1就是把原本首字符的地址變成第二個字符的地址
    }
    return len;

}


int cal1(char* str)  // 這種方法可以不用再宣告變數
{
    if(*str != '\0')
    {
        return 1+cal1(str+1);
    }
    else
    {
        return 0;
    }
}


int fib1(int n)
{

    if(n>2)
    {
        return fib1(n-1)+fib1(n-2);
    }
    else
    {
        return 1;
    }
}


int fib2(int n)
{

    int i = 1,j = 1,k = 1;
    while(n>2){
        k = i+j;
        i = j;
        j = k;
        n--;
    }
    return k;

}
