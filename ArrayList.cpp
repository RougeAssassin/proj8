#include "ArrayList.h"
#include <cstdlib>
using namespace std;
ArrayList::ArrayList()
{
	m_array = NULL;
	m_size = 0;
	m_maxsize = 0;
}
ArrayList::ArrayList(size_t count, const DataType &value)
{
	m_array = new DataType[count];
	m_size = count;
	m_maxsize = count;
	for(size_t i = 0; i < m_size; i++)
	{
		m_array[i] = value;
	}
}
ArrayList::ArrayList(const ArrayList &other)
{
	m_array = new DataType[other.m_maxsize];
	m_size = other.m_size;
	m_maxsize = other.m_maxsize;
	for(size_t i = 0; i < m_size; i++)
		m_array[i] = other.m_array[i];
}
ArrayList::~ArrayList()
{
	if(m_array != NULL)
	{
		delete [] m_array;
		m_array = NULL;
	}
	m_maxsize = 0;
	m_size = 0;
}
ArrayList& ArrayList::operator=(const ArrayList &rhs)
{
	if(this != &rhs)
	{
		m_array = new DataType[rhs.m_maxsize];
		m_size = rhs.m_size;
		m_maxsize = rhs.m_maxsize;
		for(size_t i = 0; i < m_size; i++)
			m_array[i] = rhs.m_array[i];
	}
	return *this;
}
ostream& operator<<(ostream &os, const ArrayList &arrayList)
{
	for(size_t i = 0; i < arrayList.m_size; i++)
		os << arrayList.m_array[i] << " ";
	return	os;
}
DataType* ArrayList::front()
{
	DataType* first_pt = m_array;
	if(first_pt != NULL)
	{
		return first_pt;
	}
	else
		return NULL;
}
DataType* ArrayList::back()
{
	DataType* last_pt = m_array;
	if(last_pt == NULL)
		return NULL;
	for(size_t i = 0; i < m_size-1; i++)
		last_pt++;
	return last_pt;
}
DataType* ArrayList::find(const DataType &target,
	 DataType *&previous)
{
	DataType* array_pt = m_array;
	if(array_pt != NULL)
	{
		for(size_t i = 0; i < m_size; i++)
		{
			if(*array_pt == target)
			{
				if(i > 0)
					previous = --array_pt;
				else
					previous = NULL;
				return ++array_pt;
			}
		}
	}
	previous = NULL;
	return NULL;
}
DataType* ArrayList::insertAfter(const DataType &target,
		const DataType &value)
{
	size_t pos = 0;
	DataType* array_pt = m_array;
	while(array_pt != NULL)
	{
		if(target == *array_pt)
		{
			if(m_size >= m_maxsize)
			{
				cout << m_size << " " << m_maxsize << endl;
				resize(1);
				*array_pt = m_array[pos];
			}
			for(size_t i = m_size + 1; i > pos + 1; i--)
			{
				m_array[i] = m_array[i-1];
			}
			m_array[pos + 1] = value;
			*array_pt = m_array[pos + 1];
			m_size++;
			return array_pt;
		}
		pos++;
		array_pt++;
		if(empty())
		{
			m_array[0] = value;
			*array_pt = m_array[0];
			m_size++;
			return array_pt;
		}
	}
return NULL;
}
DataType* ArrayList::insertBefore(const DataType &target,
		const DataType &value)
{
	size_t pos = 0;
	DataType* array_pt = m_array;
	while(array_pt != NULL)
	{
		if(target == *array_pt)
		{
			cout << m_size << " " << m_maxsize << endl;
			if(m_size >= m_maxsize)
			{
				resize(1);
				*array_pt = m_array[pos];
			}
			for(size_t i = m_size + 1; i > pos; i--)
			{
				m_array[i] = m_array[i-1];
			}
			m_array[pos] = value;
			m_size++;
			return array_pt;
		}
		pos++;
		array_pt++;
	}
	if(empty())
	{
		m_array[0] = value;
		*array_pt = m_array[0];
		m_size++;
		return array_pt;
	}
	return NULL;
	/*if(array_pt != NULL)
	{
		for(size_t i = 0; i < m_size; i++)
		{
			if(*array_pt == target)
			{
				pos = i-1;
				array_pt = m_array;
				array_pt += (m_size);
				if(m_size < m_maxsize && pos < m_size)
				{
					for(size_t j = m_size; j > (pos); j--)
					{
						*array_pt = *(array_pt -1);
						array_pt--;
					}
					*array_pt = value;
					m_size++;
					return array_pt;
				}
				else if(m_size < m_maxsize && pos == m_size)
				{
					*array_pt = value;
					m_size++;
					return array_pt;
				}
				else
				{
					resize(1);
					*array_pt = value;
					m_size++;
					return array_pt;
				}
			}
			array_pt++;
		}
	}
	return NULL;
	*/
}
DataType* ArrayList::erase(const DataType &target)
{
	DataType* array_pt = m_array;
	while(array_pt != NULL)
	{
		if(*array_pt == target)
		{
			for(size_t i = 0; i < m_size; i++)
			{
				*array_pt = *(array_pt + 1);
				array_pt++;
			}
			DataType temp;
			*array_pt = temp;
			m_size--;
			return array_pt;
		}
		array_pt++;
	}
	return NULL;
}
DataType& ArrayList::operator[](size_t position)
{
	return m_array[position];
}
size_t ArrayList::size() const
{
	return m_size;
}
bool ArrayList::empty() const
{
  if (m_size == 0 && m_array == NULL)
    return true;
  return false;
}
void ArrayList::clear()
{
  if (m_array != NULL)
  {
    delete [] m_array;
    m_array = NULL;
  }
  m_size = 0;
  m_maxsize = 0;
}
void ArrayList::resize(size_t count)
{
cout << " here " << endl;
	DataType tempArray[m_size];
cout << " did i make it here?" << endl;
	for (size_t i = 0; i < m_size; i++)
		tempArray[i] = m_array[i];
cout << " here now 1" << m_size << " " << m_maxsize << endl;
	delete [] m_array;
	m_array = NULL;
cout << " here now 2" << m_size << " " << m_maxsize << endl;
	m_maxsize += count;
	m_array = new DataType [m_maxsize];
	for (size_t i = 0; i < m_size; i++)
		m_array[i] = tempArray[i];
cout << "deleting the temp" << endl;

}
