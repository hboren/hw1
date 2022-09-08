#include "split.h"
#include <iostream>

using namespace std;

//got this append function from unofficial text book (David Kempe) pg. 36
void append(Node*& head, int v){
	if (head == NULL){
		head = new Node(v, NULL);
	}
	else{
		append(head->next, v);
	}
}

int main(){
	//Node* head = NULL;
	//Node* even = NULL;
	//Node* odd = NULL;
	//Node* head2 = NULL;
	//Node* head3 = NULL;
	//Node*head4 = NULL;
	//Node*head5 = NULL;
	
	//testing an empty list
	//split(head, odd, even);
	//if(odd == NULL && even == NULL){
	//	cout << "correct!";
	//}


	//testing mixed in evens and odds starting with even:
	 /*append(head, 10);
	 append(head, 11);
	 append(head, 13);
	 append(head, 20);
	 append(head, 40);
	 split(head, odd, even);
	 cout << even->value <<endl;
	 cout << even->next->value <<endl;
	 cout << even->next->next->value <<endl;
	 cout << odd->value <<endl;
	 cout << odd->next->value <<endl;*/

	//testing mixed in evens and odds starting with odd:
	 /*append(head2, 7);
	 append(head2, 9);
	 append(head2, 12);
	 append(head2, 15);
	 append(head2, 30);
	 split(head2, odd, even);
	 cout << odd->value <<endl;
	 cout << odd->next->value <<endl;
	 cout << odd->next->next->value <<endl;
	 cout << even->value <<endl;
	 cout << even->next->value <<endl;*/

	//testing evens only:
	 /*append(head3, 2);
	 append(head3, 4);
	 append(head3, 8);
	 append(head3, 10);
	 split(head3, odd, even);
	 cout << even->value << endl;
	 cout << even->next->value << endl;
	 cout << even->next->next->value << endl;
	 cout << even->next->next->next->value << endl;*/
	
	//testing all odds:
	 /*append(head4, 3);
	 append(head4, 5);
	 append(head4, 9);
	 append(head4, 15);
	 split(head4, odd, even);
	 cout << odd->value << endl;
	 cout << odd->next->value << endl;
	 cout << odd->next->next->value << endl;
	 cout << odd->next->next->next->value << endl;*/

	//testing negative numbers:
	/*append(head5, -10);
	 append(head5, -7);
	 append(head5, -4);
	 append(head5, 2);
	 split(head5, odd, even);
	 cout << even->value << endl;
	 cout << odd->value << endl;
	 cout << even->next->value << endl;
	 cout << even->next->next->value << endl;*/


	//deallocate

	/*delete head->next->next->next->next->next;
	 delete head->next->next->next->next;
	 delete head->next->next->next;
	 delete head->next->next;
	 delete head->next;
	 delete head;*/

	 /*delete head2->next->next->next->next->next;
	 delete head2->next->next->next->next;
	 delete head2->next->next->next;
	 delete head2->next->next;
	 delete head2->next;
	 delete head2;*/

	 /*
	 delete head3->next->next->next->next;
	 delete head3->next->next->next;
	 delete head3->next->next;
	 delete head3->next;
	 delete head3;*/

	 /*
	 delete head4->next->next->next->next;
	 delete head4->next->next->next;
	 delete head4->next->next;
	 delete head4->next;
	 delete head4;*/

	 	 /*
	 delete head5->next->next->next->next;
	 delete head5->next->next->next;
	 delete head5->next->next;
	 delete head5->next;
	 delete head5;*/
}