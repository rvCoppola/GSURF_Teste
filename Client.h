//---------------------------------------------------------------------------

#ifndef ClientH
#define ClientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormClientDlg : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelHostName;
	TEdit *EditHostName;
	TLabel *LabelPortNumber;
	TEdit *EditPortNumber;
	TButton *ButtonConnect;
	TClientSocket *client;
	TLabel *LabelConnectionStatus;
	TMemo *MemoComm;
	TEdit *EditRequestedJob;
	TLabel *LabelRequest;
	TButton *ButtonSend;
	void __fastcall ButtonConnectClick(TObject *Sender);
	void __fastcall clientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall clientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall clientError(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall ButtonSendClick(TObject *Sender);
	void __fastcall clientRead(TObject *Sender, TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
	__fastcall TFormClientDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormClientDlg *FormClientDlg;
//---------------------------------------------------------------------------
#endif
