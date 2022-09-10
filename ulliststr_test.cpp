/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	cout << "Testing Cases Pt1: " << endl;
  ULListStr list;
	//testing all of the commands together
  list.push_back("HEY");
  cout << "Added HEY to the list and now front is " << list.front() << endl;
  list.pop_front();
  cout << "Removed item" << endl;
  list.push_front("HI");
  cout << "Added HI to the list and now back is " << list.back() << endl;
  list.pop_back();
  cout << "Removed item" << endl;


  list.push_back("hey");
  list.push_front("sup");
  list.push_front("what's good");
  list.push_front("hi");
  list.push_front("hello");
  list.push_front("greetings");
  list.push_front("salutations");
  list.push_front("howdy");
  list.push_front("hola");
  list.push_front("yooooo");
	list.push_back("waddup");

  cout << endl;
  cout << list.get(0) << ", " << list.get(1) << ", " << list.get(2) <<
	 	", " << list.get(3) << ", " << list.get(4) << ", " << list.get(5) <<
	  ", " << list.get(6) << ", " << list.get(7) << ", " << list.get(8) << 
		", " << list.get(9) << ", " << list.get(10) << endl;


  cout << "List size after adding 11 elements is " << list.size() << endl;
  while(!list.empty()){
    cout << "Popping front item = " << list.front() << endl;
    list.pop_front();
  }
	cout << "Size = " << list.size() << endl;
  cout << "Trying to pop an item that doesn't exist" << endl;
  list.pop_front();
	cout << "Size = " << list.size() << endl;

  cout << "Repopulating list" << endl;
  list.push_back("hey");
  list.push_front("sup");
  list.push_front("what's good");
  list.push_front("hi");
  list.push_front("hello");
  list.push_front("greetings");
  list.push_front("salutations");
  list.push_front("howdy");
  list.push_front("hola");
  list.push_front("yooooo");
	list.push_back("waddup");
	cout << "Size = " << list.size() << endl;

  while(!list.empty()){
    cout << "Popping back item = " << list.back() << endl;
    list.pop_back();
  }
  cout << "Trying to pop an item that doesn't exist" << endl;
  list.pop_back();
	cout << "Size = " << list.size() << endl;
  list.push_back("100");
  list.push_front("101");
	cout << "Size = " << list.size() << endl;
	cout << endl;
	
	//test each function 
	//testing push_back
	ULListStr test;
	//push_back to an empty list
	cout << "Testing Cases Pt2: " << endl;
	test.push_back("One");
	//filling list (AKA push_back when room at end)
	test.push_back("Two");
	test.push_back("Three");
	test.push_back("Four");
	test.push_back("Five");
	test.push_back("Six");
	test.push_back("Seven");
	test.push_back("Eight");
	test.push_back("Nine");
	test.push_back("Ten");
	//push_back when no room at end
	test.push_back("Eleven");
	//adding more values to test more than two items
	cout << "size: " << test.size() << endl;

	//testing pop_back
	//if only one value and multiple items
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	//if multiple values (clearing the list up until one value left)
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	//if one value and one item
	cout << "Popping back item: " << test.back() << endl;
	test.pop_back();
	//if empty
	test.pop_back();

	//testing push_front
	//push_front to an empty item
	test.push_front("One");
	//filling the list (aka push_front when room at front)
	test.push_front("Two");
	test.push_front("Three");
	test.push_front("Four");
	test.push_front("Five");
	test.push_front("Six");
	test.push_front("Seven");
	test.push_front("Eight");
	test.push_front("Nine");
	test.push_front("Ten");
	//push_front if no space at front
	test.push_front("Eleven");

	//testing getValAtLoc using get()
	cout << "Value at index 0 after all push_fronts: " << test.get(0) << endl;
	//cout << "Trying to get value at non-existent index: " << test.get(100);
	//commented above line out because it terminates the code after throwing
	//invalid_argument

	//testing pop_front
	//if only one value and multiple items
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	//if multiple values (clearing the list up until one value left)
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	//if one value and one item
	cout << "Popping front item: " << test.front() << endl;
	test.pop_front();
	cout << "Size after popping front on all values: " << test.size() << endl;
	//if empty
	test.pop_front();
  return 0;
}
