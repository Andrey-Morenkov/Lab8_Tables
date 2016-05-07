#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <iostream>

#include "TTable.h"

using namespace std;

class TArrayTable : public TTable
{
protected:

	int      MaxSize;
	int      Curr;
	TRecord* pRec;

public:

	TArrayTable(int _size = 10)
	{
		pRec = new TRecord[_size];
		MaxSize = _size;
		Curr = -1;
		DataC = 0;
	}

	~TArrayTable()
	{
		delete[] pRec;
	}

	int GetMaxSize() const
	{
		return MaxSize;
	}

	int GetCurr() const
	{
		return Curr;
	}

	TRecord* GetpRec() const
	{
		return pRec;
	}

	int GetDataC() const
	{
		return DataC;
	}

	virtual bool isFull()
	{
		return (DataC == MaxSize);
	}

	virtual TRecord GetCurr(int _curr)
	{
		return pRec[Curr];
	}

	virtual void Reset()
	{
		Curr = 0;
	}

	virtual void GoNext()
	{
		Curr++;
	}

	virtual bool IsEnd()
	{
		return (Curr == DataC);
	}
};