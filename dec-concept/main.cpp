#include <event_dispatcher.h>
#include <iostream>
#include <string>


// example of a event_consumer derived class
class derived_consumer : public event_consumer
{
public:
	derived_consumer(std::string sName)
			: event_consumer(sName)
			{}
	
	// This is a callback function defined as subclass method
	int derived_method_callback(event * pMsg)
	{
		std::cout << getName() << " This callback is a derived class method." << std::endl;
		return 0;
	}
	
};

// This is a callback function out of any scope.
int just_a_callback_function(event * pMsg)
{
	std::cout << "This callback is just a function." << std::endl;
	return 00;	
}

// entry point
int main(int argc, char **argv)
{
	
	// three event consumer. They're notified from event.
	event_consumer ec("A");
	derived_consumer ec2("B");
	event_consumer ec3("C");
	
	// concrete_consumer is a subclass of an event_consumer
	derived_consumer cc("Concrete");
	
	const int SAMPLE_MESSAGE_ID = 1;
	const int ANOTHER_MESSAGE_ID = 2;
	const int THIRD_MESSAGE_ID = 3;
	
	// object that notify event to consumer
    event_dispatcher ed;
	
	// every consumer must subscribe to event delibery service
	ed.subscribe(&ec);
	ed.subscribe(&ec2);
	ed.subscribe(&cc);
		
	// Register lambdas as callbacks.
	// 
	// lambda as a callback, declared as setlistener parameter
	ec.setListener(SAMPLE_MESSAGE_ID, 
					[&ec](event * pMsg) 
					{ 
						std::cout << ec.getName() << " receive message " << pMsg->eventId <<std::endl; 
						return 0;
					}
					);
	// another lambda as a callback (event is different), declared as setlistener parameter
	ec.setListener(ANOTHER_MESSAGE_ID, 
					[&ec](event * pMsg) 
					{ 
					   std::cout << ec.getName() << " receive Another Msg " << pMsg->eventId << std::endl; 
					   return 0;
					}
					);
	
			   
	// lambda as a callback, declared and then set as setlistener paratmer
	// ec2 is derived from event_consumer (concrete_consumer : public event_consumer)
	auto ec2_sample_event_id_callback = [&ec2](event * pMsg) 
					{ 
						std::cout << ec2.getName() << " manage message with id" << pMsg->eventId << std::endl; 
						return 0;
					};			   				   
	ec2.setListener(SAMPLE_MESSAGE_ID, ec2_sample_event_id_callback);
					
	
	// Lambdas end here. 
						
	// Register a derived class method as a listener
	cc.setListener(SAMPLE_MESSAGE_ID, &derived_consumer::derived_method_callback);
	
	// Register a simple function as a callback
	ec2.setListener(THIRD_MESSAGE_ID, just_a_callback_function);
	
	// Register a different instance object method as event callback
	// when cc is notified of the event will cc2 will trigger its callback()
	// cc2 type can be different from cc.
	// cc subscribe to event delivery service, cc2 don't need to.
	derived_consumer cc2("WeirdStuff");
	cc.setListener(THIRD_MESSAGE_ID, &cc2, &derived_consumer::derived_method_callback);
	
	// Now we prepare some data and send some message.
	
	// 	Example event parameters structure
	event stSampleEvent = {SAMPLE_MESSAGE_ID, 1234};	
	event stAnotherEvent = {ANOTHER_MESSAGE_ID, 4567};
	event stThirdEvent = {THIRD_MESSAGE_ID, 9999};
	
	// now dispatch some events:
	ed.dispatch(ec.getHandle(), &stSampleEvent); 			// dispatch event to ec and call the callback
	ed.dispatch(ec2.getHandle(), &stSampleEvent);			// dispatch event to ec2 and call the callback
	ed.dispatch(ec2.getHandle(), &stAnotherEvent);	// no callback for this, callback not fount
	ed.dispatch(ec.getHandle(), &stAnotherEvent);	// dispatch event to ec and call the callback
	ed.dispatch(ec3.getHandle(), &stAnotherEvent);	// not subscribed to dispatcher, handle not found, event not delivered.
	ed.dispatch(cc.getHandle(), &stSampleEvent);			// dispatch the event and call derived class method
	ed.dispatch(ec2.getHandle(), &stThirdEvent);			// ec2 event will call a simple function
	ed.dispatch(cc.getHandle(), &stThirdEvent);				// cc event will trigger cc2 callback
	
	return 0;
}
