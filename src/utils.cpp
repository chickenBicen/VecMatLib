#include "../include/VecMatLib/utils.h"

double vecmatlib::magnitude( const vec2& other ) {
	return std::sqrt( other.getX() * other.getX() + other.getY() * other.getY() );
}
