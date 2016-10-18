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
	EventType evType;

protected:
	ModelingObject* object;
	ModelingObject* anotherObj;


};

class DeleteObject :public Event {

};

class ChangeDirection :public Event {

};

class StopModeling :public Event {

};
#endif