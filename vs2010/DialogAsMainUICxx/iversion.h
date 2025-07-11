#ifndef __DialogAsMainUICxx_iversion_h_
#define __DialogAsMainUICxx_iversion_h_

#define DialogAsMainUICxx_VMAJOR 1
#define DialogAsMainUICxx_VMINOR 0
#define DialogAsMainUICxx_VPATCH 0
#define DialogAsMainUICxx_VTAIL  1

#define DialogAsMainUICxxstr__(n) #n
#define DialogAsMainUICxxstr(n) DialogAsMainUICxxstr__(n)

// The following 4 are used in .rc
#define DialogAsMainUICxx_VMAJORs DialogAsMainUICxxstr(DialogAsMainUICxx_VMAJOR)
#define DialogAsMainUICxx_VMINORs DialogAsMainUICxxstr(DialogAsMainUICxx_VMINOR)
#define DialogAsMainUICxx_VPATCHs DialogAsMainUICxxstr(DialogAsMainUICxx_VPATCH)
#define DialogAsMainUICxx_VTAILs  DialogAsMainUICxxstr(DialogAsMainUICxx_VTAIL)

#define DialogAsMainUICxx_NAME "DialogAsMainUICxx"

enum {
	DialogAsMainUICxx_vmajor = DialogAsMainUICxx_VMAJOR,
	DialogAsMainUICxx_vminor = DialogAsMainUICxx_VMINOR,
	DialogAsMainUICxx_vpatch = DialogAsMainUICxx_VPATCH,
	DialogAsMainUICxx_vtail = DialogAsMainUICxx_VTAIL,
};


#endif
