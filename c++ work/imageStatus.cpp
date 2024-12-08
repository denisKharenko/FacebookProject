#include "imageStatus.h"
#include <iostream>
#pragma warning (disable : 4996)
using namespace std;


ImageStatus::ImageStatus(string text, string imagePath) :StatusObject(text)
{
	this->imagePath = imagePath;
}
ImageStatus::ImageStatus(std::string text, std::string imagePath, Date publicationDate, Clock publicationTime) : StatusObject(text, publicationDate, publicationTime)//another ctor to use when receiving data from file
{
	this->imagePath = imagePath;
}
const char* ImageStatus::getImageName() const //get functions
{
	return imagePath.c_str();
}

void ImageStatus::showStatus() const//show image status method
{
	cout << "Status details: \n";
	cout << "Status type: Image" << endl;
	cout << PICTURE_OR_VIDEO_STATUS_DISPLAY_OPTION << endl;
	cout << TEXT_STATUS_OR_IMAGE_STATUS_DISPLAY_OPTION << endl;
	cout << "Statuses text: " << getText() << endl;
	cout << "Statuses Image name: " << getImageName() << endl;
	cout << "\npublication date: ";
	publicationDate.showDate();
	cout << "\npublication time: ";
	publicationTime.showTime();
	cout << "________________" << endl;
}

bool ImageStatus::operator==(const StatusObject& other) const	//== operator that compares two statuses by text value image path value and type of status
{
	const ImageStatus* temp = dynamic_cast<const ImageStatus*>(&other);//cast the recieved status object to image status type for comparison
	if (temp == nullptr)//if type of status isnt the same return false
	{
		return (false);
	}
	else
	{
		if ((text.compare(temp->text.c_str()) == 0) && (imagePath.compare(temp->imagePath.c_str()) == 0))//compare the char * of both strings to see if its the same or not
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
}

bool ImageStatus::operator!=(const StatusObject& other) const //!= operator that compares two statuses by text value image path value and type of status
{
	bool equal = (*this == other);
	return(!equal);
}