#include <lab45.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

void compareZeroes(const BigInt& a, const BigInt& b, const BigInt& c, 
                   const BigInt& d, const BigInt& e, const BigInt& f,
                   string v1, string v2, string v3,
                   string v4, string v5, string v6);

int main()
{
  BigInt a, b(-507), c("abc"), d("275"), 
         e("     -1111111111222222222233333333334444    ");
  BigInt f(e), g("     0               "), h("       -0      ");
  BigInt i("     +0    "), j(+0), k(-0);

  cout << boolalpha;
  cout << "j == k = " << (j == k) << endl;
  cout << "j = " << j << endl;
  cout << "k = " << k << endl;
  
  cout << "e = " << e << endl;
  cout << "f = " << f << endl;
  cout << "a = " << a << endl;
  cout << "g = " << g << endl;
  cout << "h = " << h << endl;
  cout << "i = " << i << endl;
  cout << "j = " << j << endl;
  cout << "k = " << k << endl;

  compareZeroes(a, g, h, i, j, k, "a", "g", "h", "i", "j", "k");
  compareZeroes(g, h, i, j, k, a, "g", "h", "i", "j", "k", "a");
  compareZeroes(h, i, j, k, a, g, "h", "i", "j", "k", "a", "g");
  compareZeroes(i, j, k, a, g, h, "i", "j", "k", "a", "g", "h");
  compareZeroes(j, k, a, g, h, i, "j", "k", "a", "g", "h", "i");
  compareZeroes(k, a, g, h, i, j, "k", "a", "g", "h", "i", "j");

  cout << "a = " << a << endl << "b = " << b << endl;
  cout << "c = " << c << endl << "d = " << d << endl;
  cout << "e = " << e << endl << "f = " << f << endl;
  c = a = b;
  cout << "a = " << a << endl << "b = " << b << endl;
  cout << "c = " << c << endl;
  cout << "a == b = " << (a == b) << endl;
  cout << "c == b = " << (c == b) << endl;

  while (cin >> a >> b)
  {
    cout << "a = " << a << " b = " << b << endl;
    cout << a << " == " <<  b << " = " << (a == b) << endl;
    cout << a << " <  " <<  b << " = " << (a <  b) << endl;
  }

  return EXIT_SUCCESS;
}

void compareZeroes(const BigInt& a, const BigInt& b, const BigInt& c, 
                   const BigInt& d, const BigInt& e, const BigInt& f,
                   string v1, string v2, string v3,
                   string v4, string v5, string v6)
{
  cout << v1 << " == " << v1 << " = " << (a == a) << endl;
  cout << v1 << " == " << v2 << " = " << (a == b) << endl;
  cout << v1 << " == " << v3 << " = " << (a == c) << endl;
  cout << v1 << " == " << v4 << " = " << (a == d) << endl;
  cout << v1 << " == " << v5 << " = " << (a == e) << endl;
  cout << v1 << " == " << v6 << " = " << (a == f) << endl;
}

int fsaForInt(string s)
{
  int state = 0;
  string::iterator itr;

  for (itr = s.begin(); itr < s.end(); ++itr)
    switch (state)
    {
      case 0: if (isspace(*itr))
                state = 0;
              else if (*itr == '+' || *itr == '-')
                state = 1;
              else if (isdigit(*itr))
                state = 2;
              else
                state = 4;
              break;
      case 1: if (isdigit(*itr))
                state = 2;    
              else             
                state = 4;    
              break;           
      case 2: if (isdigit(*itr))
                state = 2;    
              else if (isspace(*itr))
                state = 3;
              else             
                state = 4;
              break;           
      case 3: if (isspace(*itr))
                state = 3;
              else
                state = 4;
              break;
      case 4: ;
    }

  return state == 2 || state == 3;
}

istream& operator>>(istream& input, BigInt& num)
{
  string s;

  input >> s;
  num = BigInt(s);

  return input;
}

ostream& operator<<(ostream& output, const BigInt& num)
{
  deque<char>::const_reverse_iterator itr;

  if (num.sign == NEGATIVE)
    output << '-';

  for (itr = num.digits.rbegin(); itr != num.digits.rend(); ++itr)
    output << *itr;

  return output;
}
