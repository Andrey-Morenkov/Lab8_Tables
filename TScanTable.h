#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <iostream>

#include "TArrayTable.h"

using namespace std;

class TScanTable : public TArrayTable
{
public:

	TScanTable(int _size) : TArrayTable(_size)
	{
	}

	virtual bool Find(TKey _key)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			Eff++;
			if (pRec[Curr].GetKey() == _key)
				return true;
		}
		return false;
	}

	virtual void InsRec(TRecord r)
	{
		if (isFull())
			return;
		if (!Find(r.GetKey()))
		{
			pRec[Curr] = r;
			Eff++;
			DataC++;
		}
		else
		{
			// Не могу вставить запись с таким ключом
		}
	}

	virtual void DelRec(TKey k)
	{
		if (isEmpty())
			return;
		if (Find(k))
		{
			pRec[Curr] = pRec[DataC - 1];
			DataC--;
			Eff++;
		}
		else
		{
			// Нет такой записи
		}
	}
};