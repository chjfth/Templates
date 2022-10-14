#ifndef __DialogAsMainUI_iversion_h_
#define __DialogAsMainUI_iversion_h_


#define DialogAsMainUI_VMAJOR 1
#define DialogAsMainUI_VMINOR 0
#define DialogAsMainUI_VPATCH 0
#define DialogAsMainUI_VTAIL  1

#define DialogAsMainUIstr__(n) #n
#define DialogAsMainUIstr(n) DialogAsMainUIstr__(n)

// The following 4 are used in .rc
#define DialogAsMainUI_VMAJORs DialogAsMainUIstr(DialogAsMainUI_VMAJOR)
#define DialogAsMainUI_VMINORs DialogAsMainUIstr(DialogAsMainUI_VMINOR)
#define DialogAsMainUI_VPATCHs DialogAsMainUIstr(DialogAsMainUI_VPATCH)
#define DialogAsMainUI_VTAILs  DialogAsMainUIstr(DialogAsMainUI_VTAIL)

#define DialogAsMainUI_NAME "DialogAsMainUI"

enum {
	DialogAsMainUI_vmajor = DialogAsMainUI_VMAJOR,
	DialogAsMainUI_vminor = DialogAsMainUI_VMINOR,
	DialogAsMainUI_vpatch = DialogAsMainUI_VPATCH,
	DialogAsMainUI_vtail = DialogAsMainUI_VTAIL,
};


#endif
