#pragma once

#ifdef NEDIT_WINDOWS_SHARED
	#ifdef NEDIT_BUILD
		#define NEDIT_API __declspec(dllexport)
	#else
		#define NEDIT_API __declspec(dllimport)
	#endif

#else 
	#define NEDIT_API
#endif