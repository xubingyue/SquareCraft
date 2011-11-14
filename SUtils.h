#ifndef SUTILS_H
#define SUTILS_H

#include <vector>
#include <string>

class SUtils {
public:
	SUtils();
	std::vector<std::string> Explode(std::string str,std::string del);
	float Distance(float x1,float y1,float x2,float y2);
	int Random(int max);
};

#endif