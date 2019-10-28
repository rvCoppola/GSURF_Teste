//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Client.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormClientDlg *FormClientDlg;
//---------------------------------------------------------------------------
__fastcall TFormClientDlg::TFormClientDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormClientDlg::ButtonConnectClick(TObject *Sender)
{
  if(!client->Active) {
	  client->Address = EditHostName->Text;
	  client->Port = EditPortNumber->Text.ToInt();
	  client->Open();
  }
  else
	  client->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormClientDlg::clientConnect(TObject *Sender, TCustomWinSocket *Socket)
{
  LabelConnectionStatus->Caption = "Conectado!";
  ButtonConnect->Caption = "Desconectar";
  EditRequestedJob->Enabled = True;
  ButtonSend->Enabled = True;
}
//---------------------------------------------------------------------------

void __fastcall TFormClientDlg::clientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
  LabelConnectionStatus->Caption = "<desconectado>";
  ButtonConnect->Caption = "Conectar";
  EditRequestedJob->Enabled = False;
  ButtonSend->Enabled = False;
}
//---------------------------------------------------------------------------

void __fastcall TFormClientDlg::clientError(TObject *Sender, TCustomWinSocket *Socket,
	TErrorEvent ErrorEvent, int &ErrorCode)
{
  MemoComm->Lines->Add("Erro de comunicação: " + IntToStr(ErrorCode));
}
//---------------------------------------------------------------------------



void __fastcall TFormClientDlg::ButtonSendClick(TObject *Sender)
{
  if(EditRequestedJob->Text != "")
	client->Socket->SendText(EditRequestedJob->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFormClientDlg::clientRead(TObject *Sender, TCustomWinSocket *Socket)

{
	if(Socket != NULL) {
		AnsiString s = Socket->ReceiveText();
        MemoComm->Lines->Add("Resposta: " + s);
	}
}
//---------------------------------------------------------------------------


