#ifndef _IMAGE_STATUS_H
#define _IMAGE_STATUS_H
#include "statusObject.h"

class ImageStatus :public StatusObject	//this class is the image type status that inherits from StatusObject class
{
private:
	std::string imagePath;
public:
	ImageStatus(std::string text, std::string imagePath);
	ImageStatus(std::string text, std::string imagePath, Date publicationDate, Clock publicationTime);//another ctor to use when receiving data from file
	virtual void showStatus() const override;//show image status method
	const char* getImageName() const; //get functions
	virtual bool operator==(const StatusObject& other) const override;//== operator that compares two statuses by text value image path value and type of status
	virtual bool operator!=(const StatusObject& other) const override;//!= operator that compares two statuses by text value image path value and type of status
};



#endif // !_IMAGE_STATUS_H



