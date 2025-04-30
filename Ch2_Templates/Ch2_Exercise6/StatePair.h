#ifndef STATEPAIR
#define STATEPAIR

#include <iostream>
using namespace std;

template<typename T1, typename T2>
class StatePair {
private:
   T1 key;
   T2 value;

// TODO: Define constructors
public:   
   StatePair() {
      key = T1();
      value = T2();
   }
 
   StatePair(T1 userKey, T2 userValue) {
      key = userKey;
      value = userValue;
   }
   
// TODO: Define mutators, and accessors for StatePair

// Mutuators
void SetKey(T1 k) {
   key = k;
}

void SetValue(T2 v) {
   value = v;
}

// Accessors
T1 GetKey() const {
   return key;
}

T2 GetValue() const {
   return value;
}
	
// TODO: Define PrintInfo() method
void PrintInfo() {
   cout << key << ": " << value << endl;
}

};

#endif