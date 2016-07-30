#ifndef MESSAGE_CONSUMER_H
#define MESSAGE_CONSUMER_H

#include "event.h"
#include <map>
#include <string>

typedef std::function<int (event *)> CallbackFunction;

class event_consumer
{
public:

	event_consumer(std::string sName);
	virtual ~event_consumer();

protected:
	
	// callback maps.
	std::map<int, CallbackFunction> mActionMap;
	
	// consumer namee
	std::string mName;
	
	// instance handle
	int mHandle;
	
public:

	// notify event by callin related callback, if any.
	void notify(event * pMsg);

	// set callback for a particular event
	void setListener( int eventId, CallbackFunction func);
	
	// This function allow to set a method of some instance as listener of this event.
	template<class T> void setListener(int event_id, T * t, int (T::*f)(event *))
	{
		setListener( event_id, std::bind( f, t, std::placeholders::_1 ) );	
	}
	
	// This function allow to set a method of "this" as listener
	template<class T> void setListener(int event_id, int (T::*f)(event *))
	{
		T * pt = dynamic_cast<T*>(this);
		if(pt)
		{
			setListener( event_id, std::bind( f, pt, std::placeholders::_1 ) );	
		}
	}
	
	int getHandle();
	
	std::string getName();
};

#endif // MESSAGE_CONSUMER_H
