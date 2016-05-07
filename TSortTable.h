#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <algorithm>

#include "TArrayTable.h"
#include "TScanTable.h"

using namespace std;

class TSortTable : public TArrayTable
{
public:

	TSortTable(int _size) : TArrayTable(_size)
	{
	}

	TSortTable(const TScanTable& _scant)
	{
		Curr = _scant.GetCurr();
		MaxSize = _scant.GetMaxSize();
		DataC = _scant.GetDataC();

		pRec = new TRecord[MaxSize];

		for (int i = 0; i < MaxSize; i++)
			pRec[i] = _scant.GetpRec()[i];

		sort(pRec, pRec + MaxSize);
	}

	virtual bool Find(TKey _key)
	{
		int left  = 0;
		int right = DataC-1;
		int pos;
		bool flag = false;

		while (left <= right)
		{
			Eff++;
			pos = (left + right) / 2;
			if (pRec[pos].GetKey() == _key)
			{
				right = pos;
				left = pos + 1; // останавливаем цикл костылём
				flag = true;
			}
			else
			{
				if (_key < pRec[pos].GetKey())
					right = pos - 1;
				else
					left = pos + 1;
			}
			if ((right < 0) || (pRec[pos].GetKey() != _key))
				right++;
			Curr = right;
			return flag;
		}
	}

	virtual void InsRec(TRecord r)
	{
		if (isFull())
			return;
		if (!Find(r.GetKey()))
		{
			for (int i = DataC - 1; i >= Curr; i--)
			{
				pRec[i + 1] = pRec[i];
				Eff++;
			}
			pRec[Curr] = r;
			DataC++;
		}
	}

	virtual void DelRec(TKey _key)
	{
		if (isEmpty())
			return;
		if (Find(_key))
		{
			for (int i = Curr; i < DataC; i++)
			{
				pRec[i] = pRec[i + 1];
				Eff++;
			}
			DataC--;
		}
	}
};