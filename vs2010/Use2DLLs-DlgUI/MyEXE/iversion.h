#ifndef __MyEXE_iversion_h_
#define __MyEXE_iversion_h_

#define MyEXE_VMAJOR 1
#define MyEXE_VMINOR 0
#define MyEXE_VPATCH 0
#define MyEXE_VTAIL  1

#define MyEXEstr__(n) #n
#define MyEXEstr(n) MyEXEstr__(n)

// The following 4 are used in .rc
#define MyEXE_VMAJORs MyEXEstr(MyEXE_VMAJOR)
#define MyEXE_VMINORs MyEXEstr(MyEXE_VMINOR)
#define MyEXE_VPATCHs MyEXEstr(MyEXE_VPATCH)
#define MyEXE_VTAILs  MyEXEstr(MyEXE_VTAIL)

#define MyEXE_NAME "MyEXE"

enum {
	MyEXE_vmajor = MyEXE_VMAJOR,
	MyEXE_vminor = MyEXE_VMINOR,
	MyEXE_vpatch = MyEXE_VPATCH,
	MyEXE_vtail = MyEXE_VTAIL,
};


#endif
