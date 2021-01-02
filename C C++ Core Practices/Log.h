#pragma once


#ifdef CP_DEBUG
#define LOG(X) std::cout<<X<<std::endl;
#else
#define LOG(X)
#endif