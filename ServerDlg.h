//---------------------------------------------------------------------------

#ifndef ServerDlgH
#define ServerDlgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>

//---------------------------------------------------------------------------
class TFormServerDlg : public TForm
{
__published:	// IDE-managed Components
	TServerSocket *ServerSocket;
	TButton *ButtonActivate;
	TMemo *MemoComm;
	void __fastcall ButtonActivateClick(TObject *Sender);
	void __fastcall ServerSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ServerSocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ServerSocketClientRead(TObject *Sender, TCustomWinSocket *Socket);



private:	// User declarations
    AnsiString Calculate(const AnsiString r);
public:		// User declarations
	__fastcall TFormServerDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormServerDlg *FormServerDlg;
//---------------------------------------------------------------------------
#endif
