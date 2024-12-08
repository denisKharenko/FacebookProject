#ifndef _TEXT_STATUS_H
#define _TEXT_STATUS_H
#include "statusObject.h"

class TextStatus :public StatusObject	//this class is the basic text type status that inherits from StatusObject class
{
public:
	TextStatus(std::string text);
	TextStatus(std::string text, Date publicationDate, Clock publicationTime);//another ctor to use when receiving data from file

	virtual void showStatus() const override; //show text status method
	virtual bool operator==(const StatusObject& other) const override; //== operator that compares two statuses by text value and type of status
	virtual bool operator!=(const StatusObject& other) const override; //!= operator that compares two statuses by text value and type of status
};



#endif // !_TEXT_STATUS_H