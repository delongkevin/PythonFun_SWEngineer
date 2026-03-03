// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Last Modified by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#include "EqualSeparationLinkedList.h"

/*
* Constructor.
*/
template<class element_type, uint32_t c_size>
inline LL::EqualSeparationLinkedList<element_type, c_size>::EqualSeparationLinkedList() :
	m_prevNode(NULL),
	m_nextNode(&m_buf[0]),
	m_curCount(0),
	m_isFull(false)
{
}

/*
* Insert an element. 
*
* If each element is associated with some incrementing value, and elements are only 
* inserted once this value reaches some threshold passed the previously inserted element,
* then if this threshold is doubled every time this function returns 'true', the 
* difference between each value in this list will be as close to equal as it can be.
*/
template<class element_type, uint32_t c_size>
inline bool_t LL::EqualSeparationLinkedList<element_type, c_size>::insert(element_type e)
{
	element_type* curNode = m_nextNode;
	bool_t increase_gap = false;
	m_curCount++;

	if (m_isFull)
	{
		curNode->getPrev()->setNext(curNode->getNext());
		curNode->getNext()->setPrev(curNode->getPrev());
		m_nextNode = curNode->getNext()->getNext();

		if (m_curCount >= static_cast<int32_t>(c_size / 2))
		{
			m_curCount = 0;
			m_nextNode = m_buf[0].getNext();
			increase_gap = true;
		}
	}
	else
	{
		if (m_curCount == c_size)
		{
			m_isFull = true;
			m_curCount = 0;
			m_nextNode = &m_buf[1];
			increase_gap = true;
		}
		else
		{
			m_nextNode = &m_buf[m_curCount];
		}
	}

	*curNode = e;
	curNode->setNext(NULL);

	if (m_prevNode)
	{
		m_prevNode->setNext(curNode);
	}

	curNode->setPrev(m_prevNode);
	m_prevNode = curNode;
	return increase_gap;
}

/*
* Clear this linked list.
*/
template<class element_type, uint32_t c_size>
inline void LL::EqualSeparationLinkedList<element_type, c_size>::clear()
{
	for (uint32_t i = 0; i < c_size; i++)
	{
		m_buf[i] = element_type();
	}

	m_prevNode = NULL;
	m_nextNode = &m_buf[0];
	m_curCount = 0;
	m_isFull = false;
}

/*
* Return the first element of the linked list, or head.
*/
template<class element_type, uint32_t c_size>
inline element_type* LL::EqualSeparationLinkedList<element_type, c_size>::head()
{
	element_type* ret_val;
	if (m_prevNode)
	{
		ret_val = &m_buf[0];
	}
	else
	{
		ret_val = NULL;
	}
	return ret_val;
}

/*
* Will return the next node that will be overwritten by 'insert()'.
*/
template<class element_type, uint32_t c_size>
inline element_type* LL::EqualSeparationLinkedList<element_type, c_size>::next_node() const
{
	return getM_NextNode();
}

/*
* Return whether or not the linked list is currently full.
*/
template<class element_type, uint32_t c_size>
inline bool_t LL::EqualSeparationLinkedList<element_type, c_size>::is_full() const
{
	return m_isFull;
}
