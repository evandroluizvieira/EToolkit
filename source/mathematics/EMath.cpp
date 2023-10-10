#include "../mathematics/EMath.hpp"

#include <cmath>

float EToolkit::Math::sine(float angle){
	return ::sinf(angle);
}

double EToolkit::Math::sine(double angle){
	return ::sin(angle);
}

long double EToolkit::Math::sine(long double angle){
	return ::sinl(angle);
}

float EToolkit::Math::cosine(float angle){
	return ::cosf(angle);
}

double EToolkit::Math::cosine(double angle){
	return ::cos(angle);
}

long double EToolkit::Math::cosine(long double angle){
	return ::cosl(angle);
}

float EToolkit::Math::tangent(float angle){
	return ::tanf(angle);
}

double EToolkit::Math::tangent(double angle){
	return ::tan(angle);
}

long double EToolkit::Math::tangent(long double angle){
	return ::tanl(angle);
}
