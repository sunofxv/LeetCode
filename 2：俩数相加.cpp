/***********
���ۣ��ڶ��⣺�������

***************/

#include <stdio.h>
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

 void InitStack(struct ListNode *&s)
{
	//����һ����ջ��ջ��ָ���ÿ�
	s=NULL;
}
//��ջ
bool Push(struct ListNode *&s,int e)
{
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	p->val = e;
	p->next = s;
	s = p;
	return true;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int targ = 0,sum=0;
    if(l1 == NULL && l2 == NULL)
        return 0;
    struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3->next = NULL;
    struct ListNode *tail=l3;//βָ��
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    while(p1 && p2)
    {

        if((p1->val+p2->val)>=10)
        {
            if(targ == 1)   //��һλ�Ƿ��н�λ  1����
            {
                sum = (p1->val+p2->val)%10+1;   //�н�λ+1
            }
            else
                sum= (p1->val+p2->val)%10;     //û�н�λ
            targ = 1;
        }
        else
        {
            if(targ == 1)   //��һλ�Ƿ��н�λ  1����
            {
                sum = (p1->val+p2->val)%10+1;   //�н�λ+1
                if(sum == 10)
				{
					sum = sum %10;
					targ = 1;
				}
				else
					targ = 0;
            }
            else
			{
				sum = (p1->val+p2->val)%10;     //û�н�λ
                targ = 0;
			}

        }

		p1 = p1->next;
        p2 = p2->next;
        
        if(p1 == NULL && p2 == NULL && targ ==1)
        {
            p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            //p1 = p1->next;
            p1->val = 0;
            p1->next = NULL;
            p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
           // p2 = p2->next;
		    p2->val = 0;
            p2->next = NULL;
        }
        if(p1 == NULL && p2 )
        {
			p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            //p1 = p1->next;
            p1->val = 0;
            p1->next = NULL;
        }
		if(p2 == NULL && p1 )
        {
			p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
            //p1 = p1->next;
            p2->val = 0;
            p2->next = NULL;
        }

        tail->next=(struct ListNode *)malloc(sizeof(struct ListNode));//βָ�봴��һ���µĽ���Ա㽫ֵ����

        tail=tail->next;//�ƶ�β���ʹ��ָ���������β���
		tail->val=sum;

        tail->next = NULL;
    }
    return l3->next;
}

int main()
{
	ListNode* l1,*l2,*l3;
	
	InitStack (l1);
	InitStack (l2);
	InitStack (l3);
	
	Push(l1,1);
//	Push(l1,4);
//	Push(l1,2);
//
//	Push(l2,4);
	Push(l2,9);
	Push(l2,9);
	

	l3 = addTwoNumbers(l1,l2);
	for(int i=0;i<3;i++)
	{
		printf("------- %d \n",l3->val);
		l3 = l3->next;
	}
	
    return 0;

}
