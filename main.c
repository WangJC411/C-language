#include <stdio.h>
#include <stdlib.h>

int main()
{
//�������:
//�ַ�    char  %c
//����    int   %d
//������  short %d
//�L����  long  %d
//�ξ��ȸ��c��  float %f
//�p���ȸ��c��  double %

    char x = 'a';
    printf("�ַ�x��%c\n",x);
    printf("long��͵��ֹ�����%d\n",sizeof(long));


    //��ӡ��
    //printf("%d\n",i);
    //printf("%c\n",c);

    //ݔ�룺
    //scanf("%d%d",&num1,&num2)

    //������
//    1�����泣����1,2,3������
//    2��const��ĳ�׃��  const int a=10
//    3��#define���x�Ę��R������   #define max 100
//    4��ö�e����


    const int a = 10;
    printf("��׃��a��%d\n",a);

#define MON 1
#define TUE 2
#define WEN 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

    printf("#define���R������MON��%d\n",MON);




//ö�e����������������࣬ö�e�����ã������٣�#define�����ã�
    enum Week
    {
        MON1,TUE2,WEN3,THU4,FRI5,SAT6,SUN7
    };
    enum Week day = SAT6;
    printf("ö�e����SAT6��%d\n",day);



//�ַ�����  %s
//char arr[] = "abc";  �@���ַ������䌍���Ă��|����'a','b','c','\0',\0 ���ַ����ĽY�����I
//����arr[] = "abc"�ஔ�arr[]={'a','b','c','\0'}  (\0���Ԅ��[�����ַ����e���)
//strlen(arr)  ��ʾ�ַ����L�ȣ���Ӌ��\0

    char arr[] = "abc";
    printf("�ַ������arr[]:%s\n",arr);
    printf("strlen(arr):%d\n",strlen(arr));
    printf("ת���ַ��ַ������ȣ�%d\n",strlen("c:\test\45\nest.txt")); //ת���ַ���һ���ַ�����

    /*�D�x�ַ���
            \a	����(BEL)
            \b	�˸�(BS) ������ǰλ���Ƶ�ǰһ��
            \f	��ҳ(FF)������ǰλ���Ƶ���ҳ��ͷ
            \n	����(LF) ������ǰλ���Ƶ���һ�п�ͷ
            \r	�س�(CR) ������ǰλ���Ƶ����п�ͷ
            \t	ˮƽ�Ʊ�(HT)
            \v	��ֱ�Ʊ�(VT)
            \'	������
            \"	˫����
            \\	��б��
            \aaa  ���M���D��ʮ�M����������ĵ�ASCII�a��a�ǰ��M�Ɣ��֣�
            \xaa  ʮ���M���D��ʮ�M�����������ASCII�a��x�ǹ̶��ģ�a��ʮ���M�Ɣ��֣�
    */

//������λ��  <<    >>
//������ת���ɶ����ƣ�Ȼ����������������ƣ�Ȼ��λ0

    int c = 4,d,e = 5,f;  //c:0000,0100    e:0000,0101
    d = c << 1;  //����һλ --> 0000,1000
    printf("4������һλ��%d\n",d);
    f = e >> 1;  //����һλ -->0000,0010
    printf("5������һλ��%d\n",f);


//λ����  & , | , ^  ������ת���ɶ����ƺ�ÿһλ���룬Ȼ��ֱ����λ����
//&  and
//|  or
//^  exclusive or  (��ͬȡ0����ͬȡ1��
    int g = 86, h = 100;
//g:0101,0110
//h:0110,0100
    printf("λ����and��%d\n",g&h); //68 ---> 0100,0100
    printf("λ����or��%d\n",g|h);  //118---> 0111,0110
    printf("λ����exclusive or:%d\n",g^h);  //50 ---> 0011,0010

//��0 --> ��(1)
//0   --> ��(0)

//�l������ʽ��
//���_ʽ1�����_ʽ2�����_ʽ3  --->  ���_ʽ1�ĽY��������棬�t���ر��_ʽ2��ֵ�������٣��t���ر��_ʽ3��ֵ
    int i=10,j=20,max;
    max=(i>j ? i:j);
    printf("i,j�����ֵ��%d\n",max);
//�ஔ춌�һ���Д�ʽ��
    if (i>j)
    {
        max=i;
    }
    else
    {
        max=j;
    }
    printf("i,j�����ֵ��%d\n",max);

//ԭ�a�����λ����ֵؓ���������������M�Ɣ�������0��ؓ��1��
//���a����ԭ�a���λ����̖λ����׃������λ��λȡ��
//�a�a�����a+1�õ��a�a
//���磺
//ԭ�a---> 1000 0000 0000 0000 0000 0000 1110
//���a---> 1111 1111 1111 1111 1111 1111 0001
//�a�a---> 1111 1111 1111 1111 1111 1111 0010
//�a�a������X�e��Ĵ�ŵ���ʽ
//������ԭ�a�����a�a��ؓ����Ҫ�M�������Ӌ��

//static �o�B   static int a=10��
//static ��ֲ�׃��,�ֲ�׃���������L��׃�L
//static ���ȫ��׃������׃��ȫ��׃����������׌�o�B��ȫ��׃��ֻ�����Լ����ڵ�Դ�ļ��Ȳ�ʹ��
//static �������Ҳ�Ǹ�׃�˺����������򣬻����f��׃�˺�����朽ӌ��ԣ����ⲿ朽ӌ���׃��Ȳ�朽ӌ���
//���磺
//    extern int Add(int,int);  ԭ�������{�ñ�Դ�ļ�֮��ĺ�����������@��������static����͛]�����{��


//ָ�
//��ŵ�ַ��׃������ָ�׃��
    int a1=10;
    int* p1=&a;   //ȡ��ַ��p1
    *p1=20;  //����p1��ָ�ĵ�ַ�����ֵ
    printf("�������a1ֵ��%d\n",a1);
    printf("a1�ĵ�ַ��%p\n",p1);

//��  #define name(����)  ���_ʽ
//�{�Õrֱ���� name(���w����) ����ʽ�Ϳ���
//���磺
#define MAX(x,y) (x>y? x:y)
    int qwe=MAX(3,5);
    printf("���ʹ�ã�%d\n",qwe);



//�Y���w   �����ڶ��x�}�s׃���ϣ�һ��׃���кܶ�������
//���ýY���w��ͣ�����һ��ԓ��͵ĽY���w׃��
//���磺
    struct book
    {
        char name[20],author[20];
        short price;
        long numberofbook;
    };

    struct book book1={"C�Z�Ԍ�Փ","Wang",100,1234567890};
    printf("������%s\n",book1.name);
    printf("���ߣ�%s\n",book1.author);
    printf("�r��%d\n",book1.price);
    printf("��̖��%d\n",book1.numberofbook);
//����׃���e���Ԫ��(�������ַ�����
    book1.price = 80;
    printf("������ăr��%d\n",book1.price);
//����׃���e����ַ���Ԫ��
    strcpy(book1.name,"C�Z�Ԍ�ՓII");
    printf("������ĕ�����%s\n",book1.name);






    return 0;

}
