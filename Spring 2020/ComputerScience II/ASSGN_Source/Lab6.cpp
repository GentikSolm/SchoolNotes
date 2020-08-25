#include <iostream>
#include <vector>

void f3(int& i, int& j)
{
  std::cout << "===function three===\n";
  std::cout << "i addr: " << &i << '\n';
  std::cout << "j addr: " << &j << '\n';
}

void f2(int& p, int q)
{
  std::cout << "===function two===\n";
  std::cout << "p addr: " << &p << '\n';
  std::cout << "q addr: " << &q << '\n';

  f3(p, q);
}

void f1(int a, int& b)
{
  std::cout << "===function one===\n";
  std::cout << "a addr: " << &a << '\n';
  std::cout << "b addr: " << &b << '\n';
  f2(a, b);
}

void test2() {
  int x = 1;
  int y = 2;

  std::cout << "===main()===\n";
  std::cout << "x addr: " << &x << '\n';
  std::cout << "y addr: " << &y << '\n';

  f1(x, y);
}
struct Shape
{
  Shape(std::string n)
    : name(n)
  {
     std::cout << n << " addr: " << this << '\n';
  }

  std::string name;
};


void test3()
{
  std::vector<Shape> v = { Shape("rectangle"), Shape("circle"), Shape("triangle") };
}
void test4()
{
  std::vector<Shape*> v = { new Shape("rectangle"), new Shape("circle"), new Shape("triangle") };

  // print the address of the pointer
  // i.e. We print a pointer to a pointer (Shape** s);
  for (auto it = v.begin(); it < v.end(); ++it) {
    std::cout << "Pointer stored at address: " << &*it << " points to a Shape object at address: " << *it << '\n';
  }
}

int main()
{
 test4();
}
