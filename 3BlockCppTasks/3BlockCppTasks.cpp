#include "BufferedList.h"

using namespace std;

int main()
{
    BufferedList listOne;
    Iterator* itOne = new BufferedList::ListIterator(listOne);
    itOne->start();
    listOne.addElem(itOne, 2);
    listOne.addElem(itOne, 4);
    listOne.addElem(itOne, 6);
    BufferedList listTwo = BufferedList(listOne);
    Iterator* itTwo = new BufferedList::ListIterator(listTwo);
    itTwo->start();
    listTwo.addElem(itTwo, 1);
    listTwo.addElem(itTwo, 3);
    listTwo.addElem(itTwo, 5);
    itOne = new BufferedList::ListIterator(listOne);
    itOne->start();
    cout << "List one: ";
    while (!itOne->finish()) {
        itOne->next();
        cout << itOne->getNow()->data << " ";
    } 
    itTwo = new BufferedList::ListIterator(listTwo);
    itTwo->start();
    cout << endl << "List two: ";
    while (!itTwo->finish()) {
        itTwo->next();
        cout << itTwo->getNow()->data << " ";
    }
    BufferedList listSortedTwo;
    Iterator* itSorted = new BufferedList::ListIterator(listSortedTwo);
    itSorted->start();
    itTwo = new BufferedList::ListIterator(listTwo);
    itTwo->start();
    int sizeTwo = listTwo.getLength();
    for (int i = 0; i < sizeTwo; i++) {
        itTwo->start();
        itTwo->next();
        int first = itTwo->getNow()->data;
        for (int j = 0; j < sizeTwo - i-1; j++) {
            itTwo->next();
            int second = itTwo->getNow()->data;
            if (first > second) {
                first = second;
            }
        }
        listSortedTwo.addElem(itSorted, first);
        listTwo.deleteElem(listTwo.findElem(first));
    }
    itSorted = new BufferedList::ListIterator(listSortedTwo);
    itSorted->start();
    cout << endl << "List two sorted: ";
    while (!itSorted->finish()) {
        itSorted->next();
        cout << itSorted->getNow()->data << " ";
    }
}

