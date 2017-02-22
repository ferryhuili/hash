#include <iostream>
#include "hashstruct.h"
#include <string>
using namespace std;
int main()
{
	HashMap<int ,string> hmap;

	
	hmap.put(1, "abc");
	hmap.put(1, "PPPP");
	string a;
	if(hmap.getNode(1,a)==1)
	cout << a;






	getchar();
	getchar();
	return 0;

}