#ifndef CONST_H
#define CONST_H

#define DEBUG 0
#define TRAINING 1
#define FILE_TEST 0
#define INFO 1
#define W 0
#define R 1

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
	(std::ostringstream() << std::dec << x)).str()

#endif