#include "event_consumer.h"
#include <iostream>

static int mHandleRepository = 0;

event_consumer::event_consumer(std::string sName)
{
	mName = sName;					
	mHandle = mHandleRepository; 	// assign an handle to this instance
	mHandleRepository++; 			// next, please.
	std::cout << "New consumer: " << mName << " with handle " << mHandle << std::endl;
}

event_consumer::~event_consumer()
{
}

void event_consumer::notify(event * pMsg)
{
		
	// find the event and call its callback if there's any.
	if (mActionMap.find(pMsg->eventId) != mActionMap.end())
		mActionMap[pMsg->eventId](pMsg);
	else
		std::cout << mName << " no callback defined for event " << pMsg->eventId << std::endl;
};

void event_consumer::setListener(int eventId, CallbackFunction func)
{
	mActionMap[eventId] = func;
}

int event_consumer::getHandle()
{
	return mHandle;
};

std::string event_consumer::getName()
{
	return mName;
};