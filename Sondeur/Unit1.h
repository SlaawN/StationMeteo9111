//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include "Unit2.h"
#include <Vcl.ExtCtrls.hpp>
#include <Windows.h>
#include <deque>
#include <vector>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TButton *Button3;
	TButton *Button4;
	TTimer *Timer1;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	TLabel *Label2;
	TLabel *Label3;
	TMemo *Memo4;
	TMemo *Memo5;
	TLabel *Label1;
	TLabel *Label5;
	void __fastcall OuvrirPort1Click(TObject *Sender);
	void __fastcall LirePort1Click(TObject *Sender);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FermerPort1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:
		PortRS * port;// D�clarations utilisateur
		static DWORD WINAPI RecvThread(LPVOID param);
		HANDLE sync;
		std::deque<std::vector<char> > trames;
		double longitude;
		double latitude;
public:		// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
