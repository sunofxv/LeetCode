#include<iostream>
using namespace std;

#include <string.h>
#include <stdlib.h>

#include <errno.h>

#include <windows.h>

int main()
{
	int x = 1563847412;
	int num=0;
	char oldData[100],newData;   // ת�����ַ������в���
    itoa(x,oldData,10);
    
    int length = strlen(oldData);   // ��ȡ���ݳ���
    int head,foot,middle;
      
    if(x>0)
    {
    	num=0;
    	for(int i=num;i<length/2;i++)
	    {
	        middle = oldData[i];
	        oldData[i] = oldData[length-i-1];
	        oldData[length-i-1] = middle;
	    }
         //�ж�Խ��
        if(length==10 )
		{
			int tag = (oldData[0]-'0')*100000+(oldData[1]-'0')*10000+(oldData[2]-'0')*1000+(oldData[3]-'0')*100+(oldData[4]-'0')*10+(oldData[5]-'0');
			if(tag > 214748) 
			{
				tag = (oldData[6]-'0')*1000+(oldData[7]-'0')*100+(oldData[8]-'0')*10+(oldData[9]-'0');
				if(tag>3647)
				cout << tag;
				return 0;
			}
		}
		
	}
	else
	{
		num=1;
		char head = '-';
		for(int i=num;i<length/2+1;i++)
	    {
	        middle = oldData[i];
	        oldData[i] = oldData[length-i];
	        oldData[length-i] = middle;
	    }
	    //�ж�Խ��
        if(length==11 )
		{
			int tag = (oldData[1]-'0')*100000+(oldData[2]-'0')*10000+(oldData[3]-'0')*1000+(oldData[4]-'0')*100+(oldData[5]-'0')*10+(oldData[6]-'0');
			if(tag > 214748) 
			{
				tag = (oldData[7]-'0')*1000+(oldData[8]-'0')*100+(oldData[9]-'0')*10+(oldData[10]-'0');
				if(tag>3648)
				cout << 0;
				return 0;
			}
		}
	}
    // �ж��Ƿ�Խ��
    //�ж�Խ��

//	if(strlen(oldData)>=12 && (oldData[length-1]>2)) 
    int result = 0;
    result = atoi(oldData);

	int errcode;
	errcode = GetLastError();

    //result = 9646324351;
	//else
	cout << result;
	return 0;	
} 
