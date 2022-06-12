#include <stdio.h>
#include <stdlib.h>

//類型一
struct people
{
    char name[20];
    short age;
    char id[10];
    char sex;
} pp1,pp2,pp3; //三個全局的結構體變量，可以不要


//類型二
typedef struct student1
{
    char name1[20];
    short age1;
    char id1[10];
    char sex1;
} stu; //這邊用的是typedef，所以是把這個結構體重命名為stu，之後使用會比較方便


//結構體、指針等都可以作為另一個結構體的變量
struct student
{
    char class1;
    struct people s;   //結構體
    int *point;        //指針

};

void print1(struct student tmp);  //把整個結構體傳過去
void print2(struct student *tmp);  //把指針傳過去（這種會比較好，因為只是傳一個指針，運算量很小）

int main()
{
//類型一的結構體使用
    struct people p1;  //局部結構體變量


//類型二的結構體使用
    stu p2;   //在宣告時比較簡潔

    char address[] = { "思源街13-2號1232室" };
    struct student s1 = {"A",{"Wang",23,"R10222087",'M'},address};
/*
    printf("id : %s\n",s1.s.id);
    printf("address : %s\n",s1.point);  //不知道為什麼這邊從指針裡面取值不用加*
    printf("name : %s\n",s1.s.name);
*/

    print1(s1);
    printf("-------------\n");
    print2(&s1);


    return 0;
}
void print1(struct student tmp)
{
    printf("name : %s\n",tmp.s.name);
    printf("id : %s\n",tmp.s.id);
    printf("sex : %c\n",tmp.s.sex);
    printf("address : %s\n",tmp.point);

}


void print2(struct student *tmp)
{
    printf("name : %s\n",tmp->s.name);
    printf("id : %s\n",tmp->s.id);
    printf("sex : %c\n",tmp->s.sex);
    printf("address : %s\n",tmp->point);

}
