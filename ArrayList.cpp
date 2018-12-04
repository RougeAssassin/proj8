#include "ArrayList.h"
#include <cstdlib>

ArrayList::ArrayList()
{
	m_array = NULL;
	m_size = 0;
	m_maxsize = 0;
}
ArrayList::ArrayList(size_t count, const DayaType &value)
{
	m_array = new DayaType[count];
	m_size = count;
	m_maxsize = count;
	for(int i = 0; i < m_maxsize; i++)
	{
		m_array[i] = value;
	}
}
