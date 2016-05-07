#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <iostream>

#include "TTable.h"

using namespace std;

class THashTable : public TTable
{
protected:

	int      MaxSize;
	int      curr;
	int      step;
	int      free;
	TRecord* pRec;

	int HashFunc(TKey _key)
	{
		int power = 1;
		int rez   = 0;

		for (int i = 0; i < _key.length(); i++)
		{
			rez += _key[i] * power;
			power *= 2;
		}
		return rez;
	}

public:

	THashTable(int _maxsize, int _step)
	{
		step = _step;
		MaxSize = _maxsize;

		pRec = new TRecord[MaxSize];
	}

	~THashTable()
	{
		delete[] pRec;
	}

	bool isFull()
	{
		return (DataC == MaxSize);
	}
	
	virtual bool Find(TKey _key)
	{
		curr = HashFunc(_key) % MaxSize;
		free = -1;

		for (int i = 0; i < MaxSize; i++)
		{
			if (pRec[curr].GetKey() == _key)
				return true;
			if (pRec[curr].GetKey() == "&")
			{
				if (free == -1)
					free = curr;
			}
			if (pRec[curr].GetKey == "")
				break;

			curr = (curr + step) % MaxSize;
		}
			if (free != -1)
				curr = free;
			return false;
	}

};