#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


bool operator==(const Rational& lhs, const Rational& rhs){
  if(lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator())
    return true;
  else
    return false;
};

bool operator!=(const Rational& lhs, const Rational& rhs){
  if(lhs == rhs)
    return false;
  else
    return true;
};

std::ostream& operator<<(std::ostream& stream, const Rational& number){
  stream << number.Numerator() << "/" << number.Denominator();
  return stream;
};

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

void TestConstr(){
  Rational test;
  Rational right(0, 1);
  AssertEqual(test, right);
}

void TestNegat_first(){
  Rational test(8, -16);
  Rational right(-1, 2);
  AssertEqual(test, right);
}

void TestNegat_second(){
  Rational test(-8, -16);
  Rational right(1, 2);
  AssertEqual(test, right);
}

void TestNegat_thrid(){
  Rational test(-8, 16);
  Rational right(-1, 2);
  AssertEqual(test, right);
}

void TestZero(){
  Rational test(0, 16);
  Rational right(0, 1);
  AssertEqual(test, right);
}

void TestRedus(){
  Rational test(8, 16);
  Rational right(1, 2);
  AssertEqual(test, right);
}

int main() {
  TestRunner runner;
  TestConstr();
  TestNegat_first();
  TestNegat_second();
  TestNegat_thrid();
  TestZero();
  TestRedus();
  return 0;
}
