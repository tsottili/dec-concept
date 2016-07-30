#ifndef MESSAGE_H_DEFINED
#define MESSAGE_H_DEFINED
#include <functional>


class event
{

// make eveything public in this example
public:

	// unique id for each event type
	unsigned long eventId;
	
	// sample data
	unsigned long sampleData;
};



#endif