#include <stdio.h>
#include <stdlib.h>

//���һ
struct people
{
    char name[20];
    short age;
    char id[10];
    char sex;
} pp1,pp2,pp3; //����ȫ�ֵĽY���w׃�������Բ�Ҫ


//��Ͷ�
typedef struct student1
{
    char name1[20];
    short age1;
    char id1[10];
    char sex1;
} stu; //�@߅�õ���typedef�������ǰ��@���Y���w��������stu��֮��ʹ�Õ����^����


//�Y���w��ָᘵȶ�����������һ���Y���w��׃��
struct student
{
    char class1;
    struct people s;   //�Y���w
    int *point;        //ָ�

};

void print1(struct student tmp);  //�������Y���w���^ȥ
void print2(struct student *tmp);  //��ָᘂ��^ȥ���@�N�����^�ã����ֻ�ǂ�һ��ָᘣ��\������С��

int main()
{
//���һ�ĽY���wʹ��
    struct people p1;  //�ֲ��Y���w׃��


//��Ͷ��ĽY���wʹ��
    stu p2;   //������r���^����

    char address[] = { "˼Դ��13-2̖1232��" };
    struct student s1 = {"A",{"Wang",23,"R10222087",'M'},address};
/*
    printf("id : %s\n",s1.s.id);
    printf("address : %s\n",s1.point);  //��֪����ʲ�N�@߅��ָ��e��ȡֵ���ü�*
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
