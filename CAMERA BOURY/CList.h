//---------------------------------------------------------------------------

#ifndef CListH
#define CListH
#include <windows.h>
//---------------------------------------------------------------------------
#endif

class CList {

	private:
	HANDLE hcom;
	DCB serie;
	OVERLAPPED over;

	public:

	unsigned char * allumer(unsigned char value);
	unsigned char * zoom(unsigned char value);
	unsigned char * deplaceY(unsigned char value);
	unsigned char * deplaceX(unsigned char value);
};
