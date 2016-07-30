#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <event_consumer.h>
#include "event.h"

#include <map>

class event_dispatcher
{
public:
	event_dispatcher();
	virtual ~event_dispatcher();
	
protected:
	
	// handle - pointer maps of consumers.
	std::map<int, event_consumer *> m_consumers;
	
public:

	// consumer subscribe to the service here
	void subscribe(event_consumer * pec);

	// calling this simulate a message dispatch
	void dispatch(int handle, event * pEv);
};

#endif // EVENT_DISPATCHER_H
