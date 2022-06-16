#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

char* my_strcpy(char *dest,const char*src);
int main()
{
    //編譯器有兩個版本，一個是debug，另一個是release
    //debug版本是對最原本的程式進行編譯，release版本會對原本的程式進行優化，再編譯
    //例如下面的情況：
    /*
        int i = 0;
        int arr[10] = {0};
        printf("i:%p\n",&i);
        printf("arr:%p\n",&arr[9]);
        system("pause");
        for(i = 0; i<=11; i++)  //重點在i<=11
        {
            arr[i] = 0;
            printf("OK!\n");
        }
    */

//像上面的程式，如果在debug版本裡會進入死循環，但是在release版本裡就會正常運行
//原因是在記憶體中有高地址（編號比較大）和低地址（編號比較小），局部變量會按照宣告的順序從高地址存放到低地址
//但是數組內部會從低地址存放到高地址
//例如上面的情況，假設i的地址是0x000000000061FE1C,則arr首元素的地址為000000000061FDF0,arr最後一個元素地址為000000000061FE14
//相當於在i後面只有4個字節的空位（一個整形的位置），所以在for循環中如果寫的是i<=11，arr[11]改變的是i的值
//所以for循環在到i=11的時候又會被改寫為i=0，從而行程死循環
//release版本不會出現死循環的原因是它會自動優化程式，具體表現為把arr宣告放到i宣告的前面
//這樣它們在記憶體中的位置就會互換，arr[11]的位置就不是i，改變的arr[11]的值就不會影響到循環條件



//assert() --  斷言：()裡的表達式為真，則無事發生，為假，則報錯
//使用的例子：用自定義函數來寫一個strcpy的功能（返回值為複製目標的地址）
//注意：
//1.分析參數的設計（命名，類型），返回值類型的設計，const的使用
//2.注意野指針和空指針的影響
//3.assert的使用


char arr1[] = "********************";
char arr2[] = "Hello World";
printf("%s\n",my_strcpy(arr1,arr2));

    return 0;
}

//const放在指針變量*的左邊(const char* p)時，修飾的是*p
//也就是p綁定了宣告時的變量地址，但是可以通過指針改變對應地址的值
//const放在指針變量*的右邊(char* const p)時，修飾的是p
//也就是可以改變p裡面存放的地址，但是不能通過這個地址改變對應變量的值



char* my_strcpy(char *dest,const char*src) //加const是為了讓複製源不能被改變
    //如果如果下面把複製源和複製目標寫反，在下面會改變複製源時因為const的限制，就會報錯
    {
        char *ret = dest;
        assert(dest != NULL);//斷言 -- 防止輸入的地址為野指針
        assert(src != NULL); //斷言 -- 防止輸入的地址為野指針
        while(*dest++ = *src++)   //先把*src的值給*dest，然後++，如果遇到\0，則為假（0），循環結束
        {
            ;//循環本身沒內容，在判斷的時候都進行完了
        }
        return ret;

    }
