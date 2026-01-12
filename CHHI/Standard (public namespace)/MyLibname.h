#ifndef __MyLibname_h_YYYYMMDD_
#define __MyLibname_h_YYYYMMDD_


// Include OS headers to provide OS-specific data-types used in API prototype.
// But do not include Implementation-code depending headers.
// Example:
// <windows.h> provides DWORD
// <unistd.h> provides pid_t, off64_t

#ifdef _WIN32
# include <windows.h>
#else // consider it Linux
# include <unistd.h>
#endif


//
// Check current compiler 
//

#ifdef _MSC_VER
// ...
#else // consider it GNU GCC
// ...
#endif


////////////////////////////////////////////////////////////////////////////
namespace ApiNamespace { 
////////////////////////////////////////////////////////////////////////////
// Place API function declarations in this namespace.


int getversion();


////////////////////////////////////////////////////////////////////////////
} // namespace ApiNamespace
////////////////////////////////////////////////////////////////////////////


/*
////////////////////////////////////////////////////////////////////////////
 ___                 _                           _        _   _             
|_ _|_ __ ___  _ __ | | ___ _ __ ___   ___ _ __ | |_ __ _| |_(_) ___  _ __  
 | || '_ ` _ \| '_ \| |/ _ \ '_ ` _ \ / _ \ '_ \| __/ _` | __| |/ _ \| '_ \ 
 | || | | | | | |_) | |  __/ | | | | |  __/ | | | || (_| | |_| | (_) | | | |
|___|_| |_| |_| .__/|_|\___|_| |_| |_|\___|_| |_|\__\__,_|\__|_|\___/|_| |_|
              |_|                                                           
////////////////////////////////////////////////////////////////////////////
*/
// ++++++++++++++++++ Implementation Below ++++++++++++++++++


#if defined(MyLibname_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_MyLibname) // [IMPL]


// >>> Include headers required by this lib's implementation

#include <commdefs.h> // for Uint, Uint64, enum bitwise-OR etc
#include <snTprintf.h>

// <<< Include headers required by this lib's implementation




#ifndef MyLibname_DEBUG
#include <CHHI_vaDBG_hide.h> // Suppress/invalidate vaDBG macro, from now on
#endif


////////////////////////////////////////////////////////////////////////////
namespace ApiNamespace { 
////////////////////////////////////////////////////////////////////////////
// Place API function Implementation in this namespace.


int getversion()
{
	return 1;
}


////////////////////////////////////////////////////////////////////////////
} // namespace ApiNamespace
////////////////////////////////////////////////////////////////////////////



#ifndef MyLibname_DEBUG
#include <CHHI_vaDBG_show.h> // Now restore vaDBG macro
#endif


#endif // [IMPL]


#endif // __MyLibname_h_YYYYMMDD_
