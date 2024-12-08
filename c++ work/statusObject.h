#ifndef _STATUS_OBJECT_H
#define _STATUS_OBJECT_H

#include "Date.h"
#include "Clock.h"
#include <iostream>
constexpr char TEXT_STATUS_DISPLAY_OPTION[] = "this status type can only be displayed in black and white";
constexpr char PICTURE_OR_VIDEO_STATUS_DISPLAY_OPTION[] = "this status type can be displayed in black and white or in color";
constexpr char TEXT_STATUS_OR_IMAGE_STATUS_DISPLAY_OPTION[] = "this status type can be displayed using a simple program";
constexpr char VIDEO_STATUS_DISPLAY_OPTION[] = "this status type can be displayed using a video player";
constexpr char TEXT_STATUS = 'T';
constexpr char IMAGE_STATUS = 'I';
constexpr char VIDEO_STATUS = 'V';


class StatusObject	//this class is an abstract base class for the three types of statuses
{
protected:

	std::string text;
	Date publicationDate;
	Clock publicationTime;
	StatusObject(std::string text, Date publicationDate, Clock publicationTime);//another ctor to use when receiving data from file

public:
	StatusObject(std::string text);//status ctor
	const char* getText() const; //get functions
	const Date& getDate() const;
	const Clock& getTime() const;
	virtual ~StatusObject();
	virtual void showStatus() const = 0;//abstract show status method that is implemented in in each of the three types of statuses
	virtual bool operator==(const StatusObject& other) const = 0;// abstract == operator that is implemented in each of the three types of statuses
	virtual bool operator!=(const StatusObject& other) const = 0;//abstract != operator  that is implemented in each of the three types of statuses
	friend std::ostream& operator<<(std::ostream& os, const StatusObject& status)
	{

		os << status.getText() << "\n "; 
		os << status.getDate() << "\n ";
		os << status.getTime() << "\n";
		return (os);
	}
};




#endif // !_STATUS_OBJECT_H




