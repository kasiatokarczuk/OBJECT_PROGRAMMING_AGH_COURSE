#pragma once
#include <iostream>
using namespace std;
#include "global.h"

#define FIFO_ALLOCATION_ERROR  0x01
#define FIFO_QUEUE_EMPTY 0x04
#define OTHER_ERROR      0x10



class FifoException
{
public:
    FifoException(int errCode = OTHER_ERROR);
    const char* getReason() const;  

private:
    int m_errCode;
};


//------INLINE FUNCTIONS (FifoException)-----
inline FifoException::FifoException(int errCode)
{
    m_errCode = errCode;
}

inline const char* FifoException::getReason() const
{
    switch (m_errCode)
    {
    case FIFO_ALLOCATION_ERROR:	 return "Allocation error";
    case FIFO_QUEUE_EMPTY:	     return "Queue empty";
    default:			         return "Other error";
    }
}


class FQueueu;


class FifoItem
{
private:
    friend class FQueue;

    FifoItem(FQINFO* pItem = NULL); 
    virtual ~FifoItem();  

private:
    FQINFO* m_pItem; // pointer to FQINFO
    FifoItem* m_pNext;  // pointer to the next item in the queue

};

//-----------INLINE FUNCTIONS (FifoItem)-----------
inline FifoItem::FifoItem(FQINFO* pItem)
{
    m_pItem = pItem;
    m_pNext = NULL;  
}

inline FifoItem::~FifoItem()
{
}



class FQueue
{
public:
    FQueue(); // parameterless constructor
    virtual ~FQueue();  // virtual destructor

    bool FQEmpty();   // checks if the queue is empty
    int FQEnqueue(FQINFO*);  // adds an element to the queue
    FQINFO* FQDequeue();  // removes an element from the queue
    void FQClear();  // clears the contents of the queue

private:
    FifoItem* m_pHead;  
    FifoItem* m_pTail;  
    void FQDel();
};






