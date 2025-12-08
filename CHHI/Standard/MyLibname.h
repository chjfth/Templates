#ifndef __MyLibname_h_YYYYMMDD_
#define __MyLibname_h_YYYYMMDD_


// Include OS headers to provide OS-specific data-types used in API prototype.
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


int MyLibname_getversion();




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
// (private namespace 'CHHI_MyLibname') 


#if defined(MyLibname_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_MyLibname) // [IMPL]


// >>> Include headers required by this lib's implementation

#include <commdefs.h> // for Uint, Uint64, enum bitwise-OR etc
#include <snTprintf.h>

// <<< Include headers required by this lib's implementation




#ifndef MyLibname_DEBUG
#include <CHHI_vaDBG_hide.h> // Now hide vaDBG macro
#endif




/*
    ____       _             __                                                                
   / __ \_____(_)   ______ _/ /____       ____  ____ _____ ___  ___  _________  ____ _________ 
  / /_/ / ___/ / | / / __ `/ __/ _ \     / __ \/ __ `/ __ `__ \/ _ \/ ___/ __ \/ __ `/ ___/ _ \
 / ____/ /  / /| |/ / /_/ / /_/  __/    / / / / /_/ / / / / / /  __(__  ) /_/ / /_/ / /__/  __/
/_/   /_/  /_/ |___/\__,_/\__/\___/    /_/ /_/\__,_/_/ /_/ /_/\___/____/ .___/\__,_/\___/\___/ 
                                                                      /_/                      
*/
// We should enclose this lib's implementation into private namespace.

////////////////////////////////////////////////////////////////////////////
namespace CHHI_MyLibname { 
////////////////////////////////////////////////////////////////////////////






int MyLibname_getversion()
{
	return 1;
}







////////////////////////////////////////////////////////////////////////////
} // namespace CHHI_MyLibname
////////////////////////////////////////////////////////////////////////////


/*
 ,-. .     .       .                          ,.  ;-.  ,
/    |     |       |                         /  \ |  ) |
| -. | ,-. |-. ,-: |   ,-. ;-. ,-: ,-. ,-.   |--| |-'  |
\  | | | | | | | | |   `-. | | | | |   |-'   |  | |    |
 `-' ' `-' `-' `-` '   `-' |-' `-` `-' `-'   '  ' '    '
*/

// Global space API implementation wrapper:


int MyLibname_getversion()
{
	return CHHI_MyLibname::MyLibname_getversion();
}


//
//
//

#ifndef MyLibname_DEBUG
#include <CHHI_vaDBG_show.h> // Now restore vaDBG macro
#endif


#endif // [IMPL]


#endif // __MyLibname_h_YYYYMMDD_
