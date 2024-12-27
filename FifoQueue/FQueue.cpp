#include "FQueue.h"
#include "global.h"



FQueue::FQueue()
{
	m_pHead = m_pTail = new FifoItem();
}


FQueue::~FQueue()
{
	FQClear();
	delete m_pHead;
}


bool FQueue::FQEmpty()
{
	return !m_pHead || !(m_pHead->m_pNext);
}


int FQueue::FQEnqueue(FQINFO* pItem)  
{
	FifoItem* nItem = new (nothrow) FifoItem(pItem);


	if (!nItem) 
	{
		throw FifoException(FIFO_ALLOCATION_ERROR);
	}

		m_pTail->m_pNext = nItem;
		m_pTail = nItem;
	
	return 1;
}


FQINFO* FQueue::FQDequeue()   
{

	if (FQEmpty()) 
	{
		throw FifoException(FIFO_QUEUE_EMPTY);
	}

	FQINFO* pItem = m_pHead->m_pItem;

	FQDel();
	return pItem;
}


void FQueue::FQClear()
{
	while ( !FQEmpty() ) 
	{
		delete FQDequeue();
	}
}


void FQueue::FQDel()
{
	if ( !FQEmpty() )  
	{  
		FifoItem* p = m_pHead->m_pNext;
		m_pHead->m_pNext = p->m_pNext;

		delete p;
		if (FQEmpty()) 
			m_pTail = m_pHead;
	}

}


