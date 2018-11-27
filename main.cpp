#include "ListLinked.h"
#include "ListArray.h"
#include "ListLibrary.h"
#include "CyclicListLinked.h"
#include "Triangle.h"
#include "Pentagon.h"
#include "Tetragon.h"

#include <list>

using namespace std;

void testListLinked(){

    ListLinked<int> list_ = ListLinked<int>();
    for (int i = 0; i < 10; i++)
        list_.pushBack(i);

    list_.showAll();
}

void testListArray(){

    ListArray<int> list_ = ListArray<int>();
    for (int i = 0; i < 10; i++)
        list_.pushBack(i);

    list_.showAll();
}

void testListLibrary(){

    ListLibrary<int> list_ = ListLibrary<int>();
    for (int i = 0; i < 10; i++)
        list_.pushBack(i);

    list_.showAll();
}

int main()
{
    testListLinked();
    testListArray();
    testListLibrary();

	return 0;
}
