#ifndef __MyLibname_h_YYYYMMDD_
#define __MyLibname_h_YYYYMMDD_

#include <InterpretConst.h>

namespace itc {

/*

extern CInterpretConst XXX;

extern const SingleBit2Val_st _b2v_YYY[];
extern const int N_b2v_YYY;
extern CInterpretConst YYY;

*/

} // namespace itc


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
//
#if defined(MyLibname_IMPL) || (defined CHHI_ALL_IMPL && !defined CHHI_ALL_IMPL_HIDE_MyLibname) // [IMPL] begin
// [IMPL] //
// [IMPL] //
// Include system/OS headers here
#include <stdio.h>
// [IMPL] //
// [IMPL] //
namespace itc {

// More ctor reference: My evclip 20250411.v1

/*

const Enum2Val_st _e2v_XXX[] =
{
    ITC_NAMEPAIR(NM_OUTOFMEMORY         ), // -1
    ITC_NAMEPAIR(NM_CLICK               ), // -2
    ITC_NAMEPAIR(NM_DBLCLK              ), // -3
};
CInterpretConst XXX(_e2v_XXX, ITCF_SINT);


const SingleBit2Val_st _b2v_YYY[] =
{
    ITC_NAMEPAIR(DELETE),       //   (0x00010000L)
    ITC_NAMEPAIR(READ_CONTROL), //   (0x00020000L)
    ITC_NAMEPAIR(WRITE_DAC),    //   (0x00040000L)
    ITC_NAMEPAIR(WRITE_OWNER),  //   (0x00080000L)
    ITC_NAMEPAIR(SYNCHRONIZE),  //   (0x00100000L)
};
const int N_b2v_YYY = ARRAYSIZE(_b2v_YYY);
CInterpretConst YYY(_b2v_YYY, ITCF_HEX4B);

*/


} // namespace itc
// [IMPL] //
// [IMPL] //
#endif // [IMPL] end


#endif // __MyLibname_h_YYYYMMDD_
