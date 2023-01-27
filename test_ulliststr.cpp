#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite
void print(ULListStr& ull)
{
  for(unsigned int i=0; i<=ull.size()-1; i++)
  {
    string str = ull.get(i);
    cout << str << " ";
  }
  cout << endl;
}

ULListStr* makeList(std::vector<std::string> const & values, bool pushBack)
{
	// circular list is not copyable so we have to pass it by pointer
	ULListStr* list = new ULListStr();

	if(pushBack)
	{
		for(std::vector<std::string>::const_iterator valuesIter = values.cbegin(); valuesIter != values.cend(); ++valuesIter)
		{
			list->push_back(*valuesIter);
		}
	}
	else
	{
		// push values in reverse from the front
		for(std::vector<std::string>::const_reverse_iterator valuesIter = values.crbegin(); valuesIter != values.crend(); ++valuesIter)
		{
			list->push_front(*valuesIter);
		}
	}

	return list;
}


int main(int argc, char* argv[])
{
  cout << "Running" << endl;
  ULListStr ull;
  ull.push_back("1");
  ull.push_back("2");
  ull.push_back("3");
  ull.push_back("4");
  ull.push_back("5");
  ull.push_back("6");
  ull.push_back("7");
  ull.push_back("8");
  ull.push_back("9");
  ull.push_back("10");
  ull.push_back("11");
  //ull.push_back("12");
  //ull.push_back("13");
  ull.pop_back();

  cout << ull.get(9) << endl;

/*std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};

	ULListStr* list = makeList(content, true);

	list->pop_back();

	cout << list->get(9) << endl;

	delete list;*/
 /* cout << "Size: " << ull.size() << endl;
  print(ull);

  ull.pop_back();
  print(ull);

  ull.pop_front();
  print(ull);

  ull.push_front("new");
  print(ull);

  ull.push_front("henry");
  print(ull);*/

  cout << endl;

  return 0;
}


