/*
	������ʵ��һ�� atoi ������ʹ���ܽ��ַ���ת����������

���ȣ��ú����������Ҫ�������õĿ�ͷ�ո��ַ���ֱ��Ѱ�ҵ���һ���ǿո���ַ�Ϊֹ����������ת���������£�

    �����һ���ǿ��ַ�Ϊ�����߸���ʱ���򽫸÷�����֮���澡���ܶ�����������ַ�����������γ�һ���з���������
    �����һ���ǿ��ַ������֣���ֱ�ӽ�����֮�������������ַ�����������γ�һ��������
    ���ַ�������Ч����������֮��Ҳ���ܻ���ڶ�����ַ�����ô��Щ�ַ����Ա����ԣ����ǶԺ�����Ӧ�����Ӱ�졣

ע�⣺������ַ����еĵ�һ���ǿո��ַ�����һ����Ч�����ַ����ַ���Ϊ�ջ��ַ����������հ��ַ�ʱ������ĺ�������Ҫ����ת�������޷�������Чת����

���κ�����£����������ܽ�����Ч��ת��ʱ���뷵�� 0 ��

��ʾ��

    �����еĿհ��ַ�ֻ�����ո��ַ� ' ' ��
    �������ǵĻ���ֻ�ܴ洢 32 λ��С���з�����������ô����ֵ��ΧΪ [?231,  231 ? 1]�������ֵ���������Χ���뷵��  INT_MAX (231 ? 1) �� INT_MIN (?231) ��

*/
#include <math.h>
#include<iostream>
using namespace std;

int myFunction(string str)
{
	//��ѯ����һ���ǿ��ַ�
	int head = 0;
	int tag=0,mtag,headtag=0;
	int num;
	int count,numcount;
	char cnum[100];
	HEAD:if(str[head] == ' ' || str[head] == '0')
	{
		headtag = 1;
		if(str[head] == '0' &&head+1 < str.length() && (str[head+1] < 48 || str[head+1] > 57))
		{
            return 0;
        }
        
		else
		    head++;
            goto HEAD;
	}
	if(str[head]<48 && str[head] > 57 && str[head] != '+' && str[head] != '-')
	{
		return 0;
	}
	// �жϵ�һ���ǿ��ַ��Ƿ�Ϊ + -
	if(str[head] == '+')
	{
		tag = 0;
		head++;
	}
	else if(str[head] == '-')
	{
		tag = 1;
		head++;
	}
	HEA:if(str[head] == ' ' || str[head] == '0')
	{
		head++;
		goto HEA;
	}
	count = 0;
	while(str[head] >= 48 && str[head] <= 57)
	{
		
		cnum[count] = str[head];
		count++;
		head++;
	} 
	num = 0;
	numcount = count;
    if(numcount > 10)
    {
        if(tag == 0)
        return INT_MAX;
        else if(tag == 1)
        return INT_MIN;
    }
    if(numcount==10 )
	{
			int mtag = (cnum[0]-'0')*100000+(cnum[1]-'0')*10000+(cnum[2]-'0')*1000+(cnum[3]-'0')*100+(cnum[4]-'0')*10+(cnum[5]-'0');
			if(mtag >= 214748) 
			{
				mtag = (cnum[6]-'0')*1000+(cnum[7]-'0')*100+(cnum[8]-'0')*10+(cnum[9]-'0');
				if(mtag>3647)
				{
					if(tag == 0)
	                return INT_MAX;
	                else if(tag == 1)
	                return INT_MIN;
				}
				
			}
		
	}
	for(int i=0;i<numcount;i++)
	{
		num = num+(cnum[count-1]-'0')*pow(10,i);
		count --;
	}
	if(tag == 0)
	{
		return num;
	}
	else if(tag == 1)
	{
		if((0-num) < INT_MIN)
		return INT_MIN;
		else if((0-num) > INT_MIN)
		{
			return (0-num);
		}
	}
    return 0;
}

int main()
{
	int num;
	num = myFunction("    ");
	cout << num;
	return 0;
}
 
