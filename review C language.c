#include <stdio.h>
#include <stdlib.h>

int main()
{
//數據類型:
//字符    char  %c
//整數    int   %d
//短整數  short %d
//長整數  long  %d
//單精度浮點數  float %f
//雙精度浮點數  double %

    char x = 'a';
    printf("字符x：%c\n",x);
    printf("long類型的字節數：%d\n",sizeof(long));


    //打印：
    //printf("%d\n",i);
    //printf("%c\n",c);

    //輸入：
    //scanf("%d%d",&num1,&num2)

    //常量：
//    1、字面常量（1,2,3……）
//    2、const修飾的常變量  const int a=10
//    3、#define定義的標識符常量   #define max 100
//    4、枚舉常量


    const int a = 10;
    printf("常變量a：%d\n",a);

#define MON 1
#define TUE 2
#define WEN 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

    printf("#define標識符常量MON：%d\n",MON);




//枚舉常量：（如果數量多，枚舉更好用；數量少，#define更好用）
    enum Week
    {
        MON1,TUE2,WEN3,THU4,FRI5,SAT6,SUN7
    };
    enum Week day = SAT6;
    printf("枚舉常數SAT6：%d\n",day);



//字符串：  %s
//char arr[] = "abc";  這個字符串中其實有四個東西：'a','b','c','\0',\0 是字符串的結束標誌
//所以arr[] = "abc"相當於arr[]={'a','b','c','\0'}  (\0是自動隱藏在字符串裡面的)
//strlen(arr)  表示字符串長度，不計算\0

    char arr[] = "abc";
    printf("字符串類型arr[]:%s\n",arr);
    printf("strlen(arr):%d\n",strlen(arr));
    printf("转义字符字符串长度：%d\n",strlen("c:\test\45\nest.txt")); //转义字符算一个字符长度

    /*轉義字符：
            \a	响铃(BEL)
            \b	退格(BS) ，将当前位置移到前一列
            \f	换页(FF)，将当前位置移到下页开头
            \n	换行(LF) ，将当前位置移到下一行开头
            \r	回车(CR) ，将当前位置移到本行开头
            \t	水平制表(HT)
            \v	垂直制表(VT)
            \'	单引号
            \"	双引号
            \\	反斜杠
            \aaa  八進制轉成十進制後所代表的的ASCII碼（a是八進制數字）
            \xaa  十六進制轉成十進制後所代表的ASCII碼（x是固定的，a是十六進制數字）
    */

//左右移位符  <<    >>
//把数字转化成二进制，然后整体往左或往右移，然后补位0

    int c = 4,d,e = 5,f;  //c:0000,0100    e:0000,0101
    d = c << 1;  //左移一位 --> 0000,1000
    printf("4往左移一位：%d\n",d);
    f = e >> 1;  //右移一位 -->0000,0010
    printf("5往右移一位：%d\n",f);


//位操作  & , | , ^  把数字转换成二进制后，每一位对齐，然后分别进行位操作
//&  and
//|  or
//^  exclusive or  (相同取0，不同取1）
    int g = 86, h = 100;
//g:0101,0110
//h:0110,0100
    printf("位操作and：%d\n",g&h); //68 ---> 0100,0100
    printf("位操作or：%d\n",g|h);  //118---> 0111,0110
    printf("位操作exclusive or:%d\n",g^h);  //50 ---> 0011,0010

//非0 --> 真(1)
//0   --> 假(0)

//條件操作式：
//表達式1？表達式2：表達式3  --->  表達式1的結果如果為真，則返回表達式2的值，如果為假，則返回表達式3的值
    int i=10,j=20,max;
    max=(i>j ? i:j);
    printf("i,j的最大值：%d\n",max);
//相當於寫一個判斷式：
    if (i>j)
    {
        max=i;
    }
    else
    {
        max=j;
    }
    printf("i,j的最大值：%d\n",max);

//原碼：最高位是正負值，其他是正常二進制數（正是0，負是1）
//反碼：把原碼最高位（符號位）不變，其他位按位取反
//補碼：反碼+1得到補碼
//例如：
//原碼---> 1000 0000 0000 0000 0000 0000 1110
//反碼---> 1111 1111 1111 1111 1111 1111 0001
//補碼---> 1111 1111 1111 1111 1111 1111 0010
//補碼是在電腦裡面的存放的形式
//正數的原碼就是補碼，負數才要進行上面的計算

//static 靜態   static int a=10；
//static 修飾局部變量,局部變量的生命週期變長
//static 修飾全局變量，改變了全局變量的作用域，讓靜態的全局變量只能在自己所在的源文件內部使用
//static 修飾函數，也是改變了函數的作用域，或者說改變了函數的鏈接屬性，由外部鏈接屬性變為內部鏈接屬性
//例如：
//    extern int Add(int,int);  原本可以調用本源文件之外的函數，但如果這個函數被static修飾，就沒法被調用


//指針
//存放地址的變量叫做指針變量
    int a1=10;
    int* p1=&a;   //取地址到p1
    *p1=20;  //更改p1所指的地址代表的值
    printf("更改後的a1值：%d\n",a1);
    printf("a1的地址：%p\n",p1);

//宏  #define name(參數)  表達式
//調用時直接用 name(具體參數) 的形式就可以
//例如：
#define MAX(x,y) (x>y? x:y)
    int qwe=MAX(3,5);
    printf("宏的使用：%d\n",qwe);



//結構體   應用在定義複雜變量上（一個變量有很多參數）
//利用結構體類型，創建一個該類型的結構體變量
//例如：
    struct book
    {
        char name[20],author[20];
        short price;
        long numberofbook;
    };

    struct book book1={"C語言導論","Wang",100,1234567890};
    printf("書名：%s\n",book1.name);
    printf("作者：%s\n",book1.author);
    printf("價格：%d\n",book1.price);
    printf("書號：%d\n",book1.numberofbook);
//更改變量裡面的元素(不包括字符串）
    book1.price = 80;
    printf("打折後的價格：%d\n",book1.price);
//更改變量裡面的字符串元素
    strcpy(book1.name,"C語言導論II");
    printf("更改後的書名：%s\n",book1.name);






    return 0;

}
