#ifndef _EVENT_H
#define _EVENT_H

#include <vector>

enum EventType {
	DELETE,
	CHANGE_DIRECTION,
	STOP
};


class Event {
public:

	EventType getEventType()
	{
		return type;
	}
protected:
	//ModelingObject* victim;
	//ModelingObject* predator;
	
	EventType type;
	Event(EventType eventt) {
		type = eventt;
	}

};

class DeleteObject :public Event {
public:



	

};

class ChangeDirection :public Event {

};

class StopModeling :public Event {
	StopModeling() :Event(STOP) {}
};
#endif