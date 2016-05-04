#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>

#include "TRecord.h"

using namespace std;

class TTable
{
protected:

	int DataC;    // Data Count
	int Eff;      // Efficiency

public:

	TTable()
	{
	}

	~TTable()
	{
	}

	int GetDataC() const
	{
		return DataC;
	}

	int GetEff() const
	{
		return Eff;
	}

	bool isEmpty() const
	{
		if (DataC == 0)
			return true;
		else
			return false;
	}

	virtual bool    isFull  () const    = 0;
	virtual bool    Find    (TKey k)    = 0;
	virtual void    InsRec  (TRecord r) = 0;
	virtual void    DelRec  (TKey k)    = 0;
	virtual TRecord GetCurr ()          = 0;
	// SetCurr?
	virtual void Reset()  = 0;
	virtual void GoNext() = 0;
	virtual void IsEnd()  = 0;




};