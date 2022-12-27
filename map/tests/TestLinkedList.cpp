#include "./../src/LinkedList.h"

using namespace std;

void printTestMsg(string msg);
void testAssignment(LinkedList<string>& list);
void testCopyConstructor(LinkedList<string>& list);
void testModifyingValues(LinkedList<string> list);
void testRemovingValues(LinkedList<string> list);

int main() {

    LinkedList<string> list = LinkedList<string>();

    list.add("Joe");
    list.add("Kim");
    list.add("Ryan");
    list.add("Michael");

    testAssignment(list);
    testCopyConstructor(list);
    testModifyingValues(list);
    testRemovingValues(list);


    return 0;
}

void printTestMsg(string msg)
{
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << msg << endl;
    cout << "------------------------------------------" << endl;
}

void testAssignment(LinkedList<string>& list)
{
    printTestMsg("Testing assignment operator");

    LinkedList<string> newList;
    newList = list;

    cout << "list:" << endl;
    cout << list << endl;

    cout << "newList:" << endl;
    cout << newList << endl;

    cout << "--------------------------------" << endl;
    cout << "Testing if deep copy was created" << endl << endl;

    list.add("Jenny");
    cout << "list:" << endl;
    cout << list << endl;

    cout << "newList:" << endl;
    cout << newList << endl;
}

void testCopyConstructor(LinkedList<string>& list)
{
    printTestMsg("Testing copy constructor");

    LinkedList<string> newList(list);

    cout << "list:" << endl;
    cout << list << endl;

    cout << "newList:" << endl;
    cout << newList << endl;

    cout << "--------------------------------" << endl;
    cout << "Testing if deep copy was created" << endl << endl;

    list.add("Terry");
    cout << "list:" << endl;
    cout << list << endl;

    cout << "newList:" << endl;
    cout << newList << endl;
}

void testModifyingValues(LinkedList<string> list)
{
    printTestMsg("Testing modifying values");

    cout << "list:" << endl;
    cout << list << endl;

    cout << "--------------------------------" << endl;
    cout << "Replacing \"Kim\" with \"Dwight\"" << endl << endl;

    string* val = list.getPtr("Kim");
    val->assign("Dwight");

    cout << "--------------------------------" << endl;
    cout << "Replacing \"Joel\" with \"Dwight\"" << endl;

    string* val2 = list.getPtr("Blank");
    if (val2 == nullptr) {
        cout << "\"Joel\" is in not in the list" << endl << endl;
    }

    cout << "list:" << endl;
    cout << list << endl;
}

void testRemovingValues(LinkedList<string> list)
{
    printTestMsg("Testing removing values");

    cout << "list:" << endl;
    cout << list << endl;

    cout << "--------------------------------" << endl;
    cout << "Removing first value - \"Joe\"" << endl << endl;

    list.remove("Joe");
    cout << "list:" << endl;
    cout << list << endl;

    cout << "--------------------------------" << endl;
    cout << "Removing middle value - \"Ryan\"" << endl << endl;

    list.remove("Ryan");
    cout << "list:" << endl;
    cout << list << endl;

    cout << "--------------------------------" << endl;
    cout << "Removing last value - \"Jenny\"" << endl << endl;

    list.remove("Jenny");
    cout << "list:" << endl;
    cout << list << endl;
}
