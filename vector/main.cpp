// clearing vectors
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (101);

  std::vector<int> emptyVector;
  myvector.swap(emptyVector);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<3; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}
