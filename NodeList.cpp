#include "NodeList.h"
#include <cstdlib>
using namespace std;

NodeList::NodeList()
{
  m_head = NULL;
}
NodeList::NodeList(size_t count, const DataType &value)
{
  if(count <= 1)
  {
    m_head = NULL;
  }
  else
  {
    m_head = new Node(value, NULL);
    Node *temp_pt = m_head;
    for(size_t i = 1; i < count; i++)
    {
      temp_pt->m_next = new Node(value, NULL);
      temp_pt = temp_pt->m_next;
    }
    temp_pt->m_next = NULL;
  }
}
NodeList::NodeList(const NodeList &other)
{
  if (other.m_head != NULL)
    {
      m_head = new Node (other.m_head->data(), NULL);

      Node* temp1 = m_head;
      Node* temp2 = other.m_head;
      while (temp2->m_next != NULL)
      {
          temp2 = temp2->m_next;
          temp1->m_next = new Node(temp2->data(), NULL);
          temp1 = temp1->m_next;
      }
      temp1->m_next = NULL;
    }
}
NodeList::~NodeList()
{
  clear();
}
NodeList& NodeList::operator=(const NodeList &rhs)
{
  Node* temp1 = m_head;
  Node* temp2 = rhs.m_head;
  if(this->size() < rhs.size())
  {
    clear();
    DataType temp_data;
    NodeList new_temp(rhs.size(), temp_data);
    temp1 = new_temp.m_head;
  }
  while(temp2->m_next != NULL)
  {
    temp1->m_data = temp2->data();
    temp1 = temp1->m_next;
    temp2 = temp2->m_next;
  }
  return *this;
}
ostream& operator<<(ostream &os, const NodeList& nodeList)
{
  Node* temp = nodeList.m_head;
  while(temp != NULL)
  {
    os << temp->data() << " ";
    temp = temp->m_next;
  }
  return os;
}
Node* NodeList::front()
{
  return m_head;
}
Node* NodeList::back()
{
  Node* temp_pt = m_head;
  while(temp_pt->m_next != NULL)
    temp_pt = temp_pt->m_next;
  return temp_pt;
}
Node* NodeList::find(const DataType &target,
    Node *&previous)
{
  Node* node_pt = m_head;
  if(node_pt != NULL)
  {
    if(node_pt->data() == target)
    {
      previous = NULL;
      return node_pt;
    }
    else
    {
      for(size_t i = 0; i < size(); i++)
      {
        if(node_pt->m_next->data() == target)
        {
          previous = node_pt;
          return node_pt->m_next;
        }
        node_pt = node_pt->m_next;
      }
    }
  }
  previous = NULL;
  return NULL;
}
Node* NodeList::insertAfter(const DataType & target,
    const DataType & value)
{
  Node* node_pt;
  Node* previous = NULL;
  //Node* newNode = new Node(value, NULL);
  if(empty())
  {
    m_head = new Node(value, NULL);
    return m_head;
  }
  else
  {
    node_pt = find(target, previous);
    Node* newNode = new Node(value, NULL);
    newNode->m_next = node_pt->m_next;
    node_pt->m_next = newNode;
    return newNode;
  }
  //return newNode;
}
Node* NodeList::insertBefore(const DataType &target,
    const DataType &value)
{
  Node* node_pt;
  Node* previous = NULL;
  Node* newNode = new Node(value, NULL);
  if(empty())
  {
    m_head = newNode;
    return m_head;
  }
  else
  {
    node_pt = find(target, previous);
    if(previous != NULL)
    {
      previous->m_next = newNode;
      newNode->m_next = node_pt;
      return newNode;
    }
    else
    {
      m_head = newNode;
      newNode->m_next = node_pt;
      return newNode;
    }
  }
  return NULL;
}
Node* NodeList::erase(const DataType &target)
{
  Node* node_pt;
  Node* previous = NULL;
  node_pt = find(target, previous);
  previous->m_next = node_pt->m_next;
  delete node_pt;
  if(previous->m_next != NULL)
    return previous->m_next;
  return NULL;
}
DataType& NodeList::operator[](size_t position)
{
  Node* node_pt = m_head;
  for (size_t i = 0; i < position; i++)
    node_pt++;
  return node_pt->data();
}
const DataType& NodeList::operator[](size_t position) const
{
  Node* node_pt = m_head;
  for (size_t i = 0; i < position; i++)
    node_pt++;
  return node_pt->data();
}
size_t NodeList::size() const
{
  size_t count = 0;
  Node* temp = m_head;
  while (temp != NULL)
  {
    count++;
    temp = temp->m_next;
  }
  return count;
}
bool NodeList::empty() const
{
  if (m_head == NULL)
    return true;
  return false;
}
void NodeList::clear()
{
  Node* node_pt = m_head;
  Node* previous = m_head;
  while (node_pt != NULL)
  {
    node_pt = node_pt->m_next;
    delete previous;
    previous = node_pt;
  }
  m_head = NULL;
}
