// QS.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int partion(int * pbeg, int *pe)
{
	int *ppre = pbeg;
	int *pend = pe;
	int * pstart = ppre;
	//ѡȡ����ĵ�һ��Ԫ����Ϊpivot
	int temp = *ppre;
	while (ppre!=pend)
	{
		while (pend!=ppre)
		{
			if (*pend>temp)
			{
				--pend;
			}
			else
			{
				*ppre = *pend;
				++ppre;
				break;
			}
			
		}
		
		while (ppre!=pend)
		{
			if (*ppre<=temp)
			{
				++ppre;
			}
			else
			{
				*pend = *ppre;
				--pend;
				break;
			}
		}
		
	}
	*ppre = temp;
	return ppre-pstart;
}

void quickSort(int *ppre, int *pend)
{
	if (ppre!=pend)
	{
		int pos = partion(ppre, pend);
		if (pos>1)
		{
			quickSort(ppre, &ppre[pos - 1]);
		}
		if (pend-(&ppre[pos])>1)
		{
			quickSort(&ppre[pos + 1], pend);
		}
		
	}
	/*else
	{
		return;
	}*/
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int a[] = {20,2,43,65,9,8,32,3,4,2,3,19,54,16,57};
	int a[] = {1};
	int *ppre = a;
	int len = sizeof(a) / sizeof(int);
	int *pend = &a[len - 1];
	/*int pos = partion(ppre, pend);
	cout << "pos= " << pos << endl;*/
	quickSort(ppre, pend);
	for (auto item : a)
		cout << item << " ";
	cout << endl;
	return 0;
}

