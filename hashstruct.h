const int SIZE = 128;

template<typename K,typename V>
class HashNode{
public:

	HashNode(K  key, V value) :
		_key(key), _value(value), _next(NULL){};

	K getkey(){ return _key; }

	V getvalue(){ return _value; }

	HashNode * getnext(){ return _next; };

	void setnext(HashNode * a){ HashNode::_next = a; }

	void setkey(K a){ _key = a; }

	void setvalue(V a){ _value = a; }


private:
	K _key;
	V _value;
	HashNode * _next;
};

template<typename K, typename V>
class HashMap{
public:
	HashMap()
	{
		_table = new HashNode<K,V>*[SIZE]();
		for (int i = 0; i < SIZE; ++i)
			_table[i] = 0;
	}
	~HashMap()
	{
		int i;
		HashNode<K, V> *entry;
		HashNode<K, V> *prv = 0;
		for (i = 0; i < SIZE; i++)
		{
			entry = _table[i];
			while (entry != NULL)
			{
				prv = entry;
				delete prv;
				entry = entry->getnext();
			}
		}
		delete []_table;
	}


	bool HashMap<K, V>::getNode(K key,V &value)
	{
		int sit = getsitvalue(key);
		HashNode<K, V> * entry = _table[sit];

		while (entry != NULL)
		{
			if (entry->getkey() == key)
			{
				value=entry->getvalue();
				return 1;
			}
			entry = entry->getnext();

		}
		return -1;

	}

	int HashMap<K,V>::getsitvalue(K a);

	void  HashMap<K, V>::put(K key, V value);

	int  HashMap<K, V>::deletenode(K key);

private:
	HashNode<K,V> ** _table;
};


template<typename K, typename V>
int HashMap<K, V>::deletenode(K key)
{
	int sit = getsitvalue(key);
	HashNode<K, V> * entry;
	HashNode<K, V> *prv = NULL;
	entry = _table[sit];

	while (entry != NULL && (entry->getkey()) != key)
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
	return 1;

}

template<typename K, typename V>
int HashMap<K, V>::getsitvalue(K a)
{
	return a%SIZE;
}

template<typename K, typename V>
void HashMap<K, V>::put(K  key, V value)
{
	int sit = getsitvalue(key);
	HashNode<K, V> *prv = 0;
	HashNode<K, V> *entry;
	entry = _table[sit];
	while (entry != NULL&&entry->getkey() != key)
	{
		prv = entry;
		entry = entry->getnext();
	}
	if (entry == 0)
	{
		entry = new HashNode<K, V>(key, value);
		if (prv == 0)
			_table[sit] = entry;
		else
			prv->setnext(entry);
	}
	else
		entry->setvalue(value);

}