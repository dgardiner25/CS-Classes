#include <boost/test/unit_test.hpp>
#include "list.h"
using namespace std;

BOOST_AUTO_TEST_SUITE(list)

struct fixture
{
  List<int> empty;
  List<int> l1;
  List<int> l2;
   
  fixture()
  {
    for(unsigned int i = 0; i < 10; i++)
      l1.prepend(i);
    for(unsigned int i = 9; i >= 0; i--)
      l2.append(i);
  }
};

BOOST_FIXTURE_TEST_CASE(constructor, fixture)
{
  BOOST_CHECK_EQUAL(empty.length(), 0);
  BOOST_CHECK_EQUAL(empty.empty(), true); 
}

BOOST_FIXTURE_TEST_CASE(copy_constructor, fixture)
{
  List<int> copy(l1);
  BOOST_CHECK_EQUAL(copy.length(), l1.length());
  BOOST_CHECK_EQUAL(copy.empty(), l1.empty());
}

BOOST_FIXTURE_TEST_CASE(prepend, fixture)
{
  BOOST_CHECK_EQUAL(l1.head(), 9);
}

BOOST_FIXTURE_TEST_CASE(append, fixture)
{
  BOOST_CHECK_EQUAL(l2.head(), 9);
}

BOOST_FIXTURE_TEST_CASE(pop, fixture)
{
  l2.pop();
  BOOST_CHECK_EQUAL(l2.head(), 8);
}


BOOST_AUTO_TEST_SUITE_END()
