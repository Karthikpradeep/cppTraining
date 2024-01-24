// forward list is a singly linked list in c++
/*
 	assign() -> to assign values to forward list
	push_front() -> push elements to front of the list
	emplace_front() -> insert element in the front without copying
	pop_front() -> delete element from the front of the list 
	insert_after() -> insert value at any position
	emplace_after() -> same as insert after without creating a copy
	erase_after() -> erase elements from a particular position
	clear() -> delete all elements in the list
	splice_after() -> splice two list
	unique() -> remove duplicate elements
	reverse() -> reverse teh order of the elements of the list
*/

#include<iostream>
#include<forward_list>

using namespace std;

void display(forward_list<int> fList){
        cout<<"Elements of the forward list are - ";

	for(int i : fList){
		cout<<i<<" ";
	}
	cout<<endl;
}
int main(){
	forward_list<int> fList1 = {3,1,6,2,34,21,99,45,100,69};
	display(fList1);
	//inserting to the list
	fList1.assign({55,44,77});
	display(fList1);

	fList1.push_front(33);
	display(fList1);

	fList1.emplace_front(22);
	display(fList1);
	fList1.emplace_front(88);
	display(fList1);

	forward_list<int> :: iterator iter;
	iter = fList1.insert_after(fList1.begin(),{2,3,4});
	display(fList1);
	//delete element
	iter = fList1.begin();
	advance(iter,4);
	iter = fList1.erase_after(iter);//delete element from a particular position
	display(fList1);

	fList1.remove(2);//remove all occurences of 2
	display(fList1);
	
	fList1.clear();
	display(fList1);

	fList1.assign({1,2,3});
	forward_list<int> fList2({4,5,6});
	fList2.splice_after(fList2.begin(),fList1);
	display(fList2);


	return 0;
}
