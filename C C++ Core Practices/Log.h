#pragma once


#ifdef CP_DEBUG
#define LOG(X) std::cout << X << std::endl
#define LOG_ANY(X) X
#else
#define LOG(X)
#define LOG_ANY(X)
#endif