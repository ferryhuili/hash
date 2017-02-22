const int SIZE	=128;
class HashNode{
public:

	HashNode(unsigned int  key, int value) :
		_key(key), _value(value), _next(0){};

	unsigned int getkey(){ return _key; }
	int getvalue(){ return _value; }
	HashNode * getnext(){ return _next; };

	void setnext(HashNode * a){  _next=a; }
	void setkey(unsigned a){ _key = a; }
	void setvalue(int a){ _value = a; }


private:
	unsigned int _key;
	int       _value;
	HashNode * _next;
};

class HashMap{
public:
	HashMap()
	{
		_table = new HashNode*  [SIZE];
		for (int i = 0; i < SIZE; ++i)
			_table[i] = 0;
	}
	~HashMap()
	{
		int i;
		HashNode *entry;
		HashNode *prv=0;
		for (i = 0; i < SIZE; i++)
		{
			entry = _table[i];
			while (entry!= NULL)
			{
				prv = entry;
				delete prv;
				entry = entry->getnext();
			}
		}
		delete _table;
	}
	int getsitvalue(unsigned int a);
	
	void put(unsigned key, int value);
	
	int getNode(unsigned int key);
	int deletenode(unsigned int key);

private:
	HashNode ** _table;
};

int HashMap::getNode(unsigned int key)
{
	int sit = getsitvalue(key);
	HashNode * entry = _table[sit];

	while (entry != NULL)
	{
		if (entry->getkey() == key) return entry->getvalue();
		entry = entry->getnext();

	}
	return -1;
	
}
int HashMap::deletenode(unsigned int key)
{
	int sit = getsitvalue(key);
	HashNode * entry;
	HashNode *prv=NULL;
	entry = _table[sit];

	while (entry != NULL&&(entry->getkey() )!= key)
	{
		prv = entry;
		entry = entry->getnext();
	}
	if (entry == NULL)
		return -1;
	else
	{
		if (prv == NULL)
			_table[sit] = NULL;
		else
			prv->setnext(entry->getnext());


		delete entry;
	}
	
}
int HashMap::getsitvalue(unsigned int a)
{
	return a%SIZE;
}
void HashMap::put(unsigned int  key, int value)
{
	int sit = getsitvalue(key);
	HashNode *prv = 0;
	HashNode *entry;
	entry = _table[sit];
	while (entry != NULL&&entry->getkey() != key)
	{
		prv = entry;
		entry = entry->getnext();
	}
	if (entry == 0)
	{
		entry = new HashNode(key,value);
		if (prv == 0)
			_table[sit] = entry;
		else
			prv->setnext(entry);
	}
	else
		prv->setnext(new HashNode(key, value));

}