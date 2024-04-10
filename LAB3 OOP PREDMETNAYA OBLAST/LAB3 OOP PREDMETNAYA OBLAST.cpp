#include "array.cpp"



int main()
{
	FIO fio("sw", "sw", "sw");
	fio.name = "Papapap";
	fio.surname = "ahaha";
	fio.fathername = "eehehee";
	
	std::string town = "hoh	oho";
	std::string street = "hahahah";
	auto ad = new adress(town, street, 1);

	auto b1 = new buyer(fio, *ad);
	container<buyer, 3> list;

	list.fill(*b1);
	list[0];
	
	for (int i = 0; i < 3; i++)
		cout << list[i].fio.name <<"\n";
	
	
	

	//std::cout << __cplusplus << std::endl;
	return 0;	
}
