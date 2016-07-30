#include "event_dispatcher.h"
#include <iostream>

event_dispatcher::event_dispatcher()
{
}

event_dispatcher::~event_dispatcher()
{
}


void event_dispatcher::subscribe(event_consumer * pmc)
{
	m_consumers[pmc->getHandle()] = pmc;
	std::cout << pmc->getName() << " subscribe with handle " << pmc->getHandle() << std::endl;
}

void event_dispatcher::dispatch(int handle, event * pMsg)
{
	// find the consumer and call its notify function
	if (m_consumers.find(handle) != m_consumers.end())
	{
		m_consumers[handle]->notify(pMsg);
	}
	else
	{
		std::cout << "Cannot find object with handle " << handle << std::endl;
	}
}