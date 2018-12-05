#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main(){

  //1
  ArrayList ar_lst;
  cout << ar_lst << "default ctor array" << endl;
  NodeList nd_lst;
  cout << nd_lst << "default ctor node" << endl;
  //2
  DataType def_value1(3000, 250.0);
  DataType def_value2(300, 25.0);
  ArrayList al_parameterized(5, def_value1);
  cout << "parm ctor array " << al_parameterized << endl;
  NodeList nl_parameterized(5, def_value2);
  cout << "parm ctor node " << nl_parameterized << endl;
  //3
  ArrayList al_copy(al_parameterized);
  cout << "copy ctor array " << al_copy << endl;
  NodeList nl_copy (nl_parameterized);
  cout << "copy ctor node " << nl_copy << endl;
  //5
  DataType assign_value(840, 60.0);
  DataType access_value(30, 10.0), in_value(120, 25.0);
  ArrayList al_assign(6, in_value);
  al_assign = ArrayList(6, assign_value);
  cout << "assignment op for array " << al_assign << endl;
  ArrayList al_access(6, access_value);
  cout << "assignment op for array " << al_access << endl;

  NodeList nl_assign(6, in_value);
  nl_assign = NodeList(6, assign_value);
  cout << "assignment op for node " << nl_assign << endl;
  NodeList nl_access(6, access_value);
  cout << "assignment op for node " << nl_access << endl;
  //(7),(8)
  ArrayList al_first(al_assign);
  ArrayList al_last(al_assign);
  cout << "front test for array " << *(al_first.front());
  cout << endl;
  cout << "back test for array" << *(al_last.back());
  cout << endl;
  NodeList nl_first(nl_assign);
  NodeList nl_last(nl_assign);
  if(nl_first.front() != NULL)
    cout << "front test for node" << endl;
  else
    cout << "OOPS!" << endl;
  if(nl_last.back() != NULL)
    cout << "back test for node" << endl;
  else
    cout << "DOUBLE OOPS!" << endl;
  //(9)
  DataType* prev_data = NULL;
  DataType* find_data = al_access.find(access_value, prev_data);
  cout << "find array " << *find_data << endl;
  Node* prev_node = NULL;
  Node* find_node = nl_access.find(access_value, prev_node);
  if (find_node != NULL)
  {
    cout << "find node " << endl;
  }
  else
  {
    cout << "OOPS DIDN'T FIND! " << endl;
  }
  //(10),(11)
  DataType* ins_after = al_assign.insertAfter(assign_value, in_value);
  cout << "insertAfter array " << al_assign << endl;
  DataType* ins_before = al_assign.insertBefore(assign_value, in_value);
  cout << "insertBefore array " << al_assign << endl;

  Node* in_after = nl_assign.insertAfter(assign_value, in_value);
  if (in_after != NULL)
  {
    cout << "insertAfter node " << endl;
  }
  else
  {
    cout << "DIDN'T INSETAFTER... NODE" << endl;
  }
cout << " right around here" << endl;
  Node* in_before = nl_assign.insertBefore(assign_value, in_value);
  if (in_before != NULL)
  {
    cout << "TRUE" << endl;
  }
  else
  {
    cout << "FALSE" << endl;
  }

  //(14)
  cout << al_assign[2] << al_assign << endl;
  cout << al_access[2] << al_access << endl;
  cout << nl_assign[2] << nl_assign << endl;//need to fix the bracket op ovld
  cout << nl_access[2] << nl_access << endl;
  //(15)
  ArrayList al_size(10, assign_value);
  cout << al_size.size() << endl;
  NodeList nl_size(8, assign_value);
  cout << nl_size.size() << endl;
  //(16),(17)
  al_access.clear();
  cout << boolalpha << al_access.empty() << endl;

  nl_access.clear();
  cout << boolalpha << nl_access.empty() << endl;

  al_assign.clear();
  nl_assign.clear();
  al_parameterized.clear();
  nl_parameterized.clear();
  al_copy.clear();
  nl_copy.clear();
  al_first.clear();
  nl_first.clear();
  al_last.clear();
  nl_last.clear();

  return 0;
}
