#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>

using namespace std;

typedef string TKey;
typedef string TValue;

class TRecord
{
	TKey key;
	TValue val;


public:

	TRecord(TKey _key = NULL, TValue _val = NULL)
	{
		key = _key;
		val = _val;
	}

	~TRecord()
	{
	}

	void SetKey(TKey _key)
	{
		key = _key;
	}

	void SetVal(TValue _val)
	{
		val = _val;
	}

	TKey GetKey() const
	{
		return key;
	}

	TValue GetVal() const
	{
		return val;
	}

	bool operator == (const TRecord& r)
	{
		if (key == r.key)
			return true;
		else
			return false;
	}

	bool operator > (const TRecord& r)
	{
		if (key > r.key)
			return true;
		else
			return false;
	}

	bool operator < (const TRecord& r)
	{
		if (key < r.key)
			return true;
		else
			return false;
	}

	bool operator !=(const TRecord& r)
	{
		if (key != r.key)
			return true;
		else
			return false;
	}

	friend bool operator ==(TKey key1, TKey key2)
	{
		temp_key1 = key1.stoi // TODO сравнение Key-ев
	}
};
