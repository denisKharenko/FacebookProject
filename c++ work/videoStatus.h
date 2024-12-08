#ifndef _VIDEO_STATUS_H
#define _VIDEO_STATUS_H
#include "statusObject.h"

class VideoStatus :public StatusObject	//this class is the video type status that inherits from StatusObject class
{
private:
	std::string videoPath;
public:
	VideoStatus(std::string text, std::string videoPath);
	VideoStatus(std::string text, std::string videoPath, Date publicationDate, Clock publicationTime);//another ctor to use when receiving data from file
	virtual void showStatus() const override;//show video status method
	const char* getVideoName() const; //get functions
	virtual bool operator==(const StatusObject& other) const override;//== operator that compares two statuses by text value video path value and type of status
	virtual bool operator!=(const StatusObject& other) const override;//!= operator that compares two statuses by text value video path value and type of status
};


#endif // !_VIDEO_STATUS_H