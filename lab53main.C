#include <iostream>
#include <sstream>
#include <string>
#include <lab53.h>

using namespace std;

int main()
{
  int num;
  istringstream in;
  string inputLine;
  bool intGroup = true;
  miniStack<int> intStack;
  miniStack<string> wordStack;

  cout << "intStack.size() = " << intStack.size() << endl;
  cout << "intStack.empty() = " << boolalpha << intStack.empty() << endl;

  while (getline(cin, inputLine))
    if (inputLine == "::")
      intGroup = false;
    else if (intGroup)
    {
      in.clear();
      in.str(inputLine);
      in >> num;
      intStack.push(num);
    }
    else
      wordStack.push(inputLine);

  cout << "intStack.size() = " << intStack.size() << endl;
  cout << "intStack.empty() = " << intStack.empty() << endl;

  while (!intStack.empty())
  {
    cout << intStack.top();
    intStack.pop();
    cout << " intStack.size() = " << intStack.size();
    cout << " intStack.empty() = " << intStack.empty() << endl;
  }

  cout << "wordStack.size() = " << wordStack.size() << endl;
  cout << "wordStack.empty() = " << wordStack.empty() << endl;

  while (!wordStack.empty())
  {
    cout << wordStack.top();
    wordStack.pop();
    cout << " wordStack.size() = " << wordStack.size();
    cout << " wordStack.empty() = " << wordStack.empty() << endl;
  }

  return 0;
}
