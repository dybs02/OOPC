#include "./../src/Map.h"

using namespace std;

void printTestMsg(string msg);
void testAssignment(Map<int, string>& map);
void testCopyConstructor(Map<int, string>& map);
void testModifyingValues(Map<int, string> map);
void testRemovingValues(Map<int, string> map);

int main() {

    Map<int, string> map = Map<int, string>();

    map.add(111, "Pam");
    map.add(222, "Jim");
    map.add(333, "Kevin");

    testAssignment(map);
    testCopyConstructor(map);
    testModifyingValues(map);
    testRemovingValues(map);

    return 0;
}

void printTestMsg(string msg)
{
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << msg << endl;
    cout << "------------------------------------------" << endl;
}

void testAssignment(Map<int, string>& map)
{
    printTestMsg("Testing assignment operator");

    Map<int, string> newMap;
    newMap = map;

    cout << "map:" << endl;
    cout << map << endl;

    cout << "newMap:" << endl;
    cout << newMap << endl;

    cout << "--------------------------------" << endl;
    cout << "Testing if deep copy was created" << endl << endl;

    map.add(123, "Stanley");
    cout << "map:" << endl;
    cout << map << endl;

    cout << "newMap:" << endl;
    cout << newMap << endl;
}

void testCopyConstructor(Map<int, string>& map)
{
    printTestMsg("Testing copy constructor");

    Map<int, string> newMap(map);

    cout << "map:" << endl;
    cout << map << endl;

    cout << "newMap:" << endl;
    cout << newMap << endl;

    cout << "--------------------------------" << endl;
    cout << "Testing if deep copy was created" << endl << endl;

    map.add(456, "Kelly");
    cout << "map:" << endl;
    cout << map << endl;

    cout << "newMap:" << endl;
    cout << newMap << endl;
}

void testModifyingValues(Map<int, string> map)
{
    printTestMsg("Testing modifying values");

    cout << "map:" << endl;
    cout << map << endl;

    cout << "--------------------------------" << endl;
    cout << "Replacing \"Jim\" with \"Dave\"" << endl << endl;

    string* val = map.find(222);
    val->assign("Dave");

    cout << "map:" << endl;
    cout << map << endl;

    cout << "--------------------------------" << endl;
    cout << "Replacing value at key = 1 with \"Oscar\"" << endl;

    string* val2 = map.find(1);
    if (val2 == nullptr) {
        cout << "Key = 1 is not in the map" << endl << endl;
    }

    cout << "map:" << endl;
    cout << map << endl;
}

void testRemovingValues(Map<int, string> map)
{
    printTestMsg("Testing removing values");

    cout << "map:" << endl;
    cout << map << endl;

    cout << "--------------------------------" << endl;
    cout << "Removing first value - key = 111" << endl << endl;

    map.remove(111);
    cout << "map:" << endl;
    cout << map << endl;

    cout << "--------------------------------" << endl;
    cout << "Removing middle value - key = 333" << endl << endl;

    map.remove(333);
    cout << "map:" << endl;
    cout << map << endl;

    cout << "--------------------------------" << endl;
    cout << "Removing last value - key = 456" << endl << endl;

    map.remove(456);
    cout << "map:" << endl;
    cout << map << endl;
}