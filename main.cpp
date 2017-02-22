#include <iostream>
#include "hashstruct.h"
using namespace std;
int main()
{
	HashMap hmap;

	hmap.put(3,5);
	hmap.put(191,6);
	hmap.put(5,6);
	hmap.put(6,3);
	hmap.put(194,7);

	cout << hmap.getNode(5)<<" "<<hmap.getNode(191);
	hmap.deletenode(6);
	cout << hmap.getNode(6);

	getchar();
	getchar();
	return 0;

}