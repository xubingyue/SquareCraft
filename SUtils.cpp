#include "PCH.h"

SUtils::SUtils() {
	srand((unsigned int)time(NULL));
}

std::vector<std::string> SUtils::Explode(std::string str,std::string del) {
	char *pch;
	std::vector<std::string> result;
	pch=strtok((char *)str.c_str(),del.c_str());
	while(pch!=NULL) {
		result.push_back(pch);
		pch=strtok(NULL,del.c_str());
	}
	return result;
}

float SUtils::Distance(float x1,float y1,float x2,float y2) {
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int SUtils::Random(int max) {
	return rand()%max;
}