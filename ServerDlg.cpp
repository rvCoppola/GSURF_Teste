//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ServerDlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormServerDlg *FormServerDlg;
//---------------------------------------------------------------------------
__fastcall TFormServerDlg::TFormServerDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormServerDlg::ButtonActivateClick(TObject *Sender)
{
  if (ServerSocket->Active) {
	  ServerSocket->Active = False;
	  ButtonActivate->Caption = "Ativar";
	  MemoComm->Lines->Add("Servidor desativado!");
  }
  else {
	  ServerSocket->Active = True;
	  ButtonActivate->Caption = "Desativar";
	  MemoComm->Lines->Add("Servidor ativado!");
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormServerDlg::ServerSocketClientConnect(TObject *Sender, TCustomWinSocket *Socket)

{
	if(Socket != NULL)
		MemoComm->Lines->Add("Cliente conectado: " +
			Socket->LocalAddress + ", porta: " +
			IntToStr(Socket->LocalPort)
			);
}
//---------------------------------------------------------------------------

void __fastcall TFormServerDlg::ServerSocketClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
	if(Socket != NULL)
		MemoComm->Lines->Add("Cliente desconectado: " +
			Socket->LocalAddress + ", porta: " +
			IntToStr(Socket->LocalPort)
			);
}
//---------------------------------------------------------------------------

AnsiString TFormServerDlg::Calculate(const AnsiString r)

{
	MemoComm->Lines->Add("Tamanho: " + IntToStr(r.Length()));
	if(r.Length() > 0) {

		int   i = 0;
		char  _oper[10];
		float _parc[10];

		bool  _decimal  = False;
		bool  _operador = False;

		char *s = r.c_str();
		char *e = s + r.Length();

        // Parse para separar as parcelas e as operações
		for(char *p = s;p < e;p++) {

			switch (*p) {

				case '.':
					if(_decimal)
						return "Sinal decimal duplicado na posição: " +
							IntToStr(p - s + 1) + "!";
					else
					   _decimal = True;

					break;

				case '*':
				case '+':
				case '-':
				case '/':
					if(_operador) {
						return "Operador extra na posição: " +
							IntToStr(p - s + 1) + "!";
					} else
					if(p == s) {
						return "Operador antes da parcela!";
					} else {
						_operador  = True;
						_decimal   = False;
						_parc[i]   = atof(s);
						_oper[i++] = *p;
						s = p + 1;
					}

					break;

				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					_operador = False;

					if((p == e - 1) && (p > s)) {
						_parc[i]   = atof(s);
						_oper[i++] = '=';
					}

					break;
			default:
				char err[40];
				sprintf(err, "Caracter inválido \'%c\' na posição %i!",
					*p, p - s + 1);

				return err;
			} // switch (*p)
		} // for(char *p = s;p < e;p++)

        // Apresenta as parcelas e operações obtidas no Parse:
		for(int j = 0;j < i;j++) {
			char buff[80];
			sprintf(buff, "Parcela[%i]: %f (%c)", j + 1, _parc[j], _oper[j]);
			MemoComm->Lines->Add(buff);
		} // for(int j = 0;j < i;j++)

		int c = 0;
		while (i > 1) {

			for(int j = 0;j < i - 1;j++) {

				  if((_oper[j + 1] == '=') ||                          // só há uma operação
					 (_oper[j]     == '*') || (_oper[j]     == '/') || // ou a expressão atual tem precedência
					 (_oper[j + 1] == '+') || (_oper[j + 1] == '-')) { // ou está no mesmo nível da próxima

						// Verifica possível divisão por zero:
						if((_oper[j] == '/') && (_parc[j + 1] == 0.0))
						  return "Divisão por zero entre as parcelas " +
							IntToStr(j + 1) + " e " + IntToStr(j + 2) + "!";

						// Opera a parcela atual com a seguinte:
						switch(_oper[j]) {
						  case '*':
							_parc[j] = _parc[j] * _parc[j + 1];
							break;

						  case '+':
							_parc[j] = _parc[j] + _parc[j + 1];
							break;

						  case '-':
							_parc[j] = _parc[j] - _parc[j + 1];
							break;

						  case '/':
							_parc[j] = _parc[j] / _parc[j + 1];
							break;
						}

						// Transporta as parcelas e operações seguintes:
						_oper[j] = _oper[j + 1];
						for(int t=j + 1;t < i - 1;t++) {
							_parc[t] = _parc[t + 1];
							_oper[t] = _oper[t + 1];
						}

						i--;
				  } // if((_oper[j]   == '*') || (_oper[j]   == '/') ||
			} // for(int j = 0;j < i - 1;j++)

			// Apresenta as parcelas e operações reorganizadas:
            MemoComm->Lines->Add("");
			MemoComm->Lines->Add("Iteração: " + IntToStr(++c));
			for(int j = 0;j < i;j++) {
				char buff[80];
				sprintf(buff, "Parcela[%i]: %f (%c)", j + 1, _parc[j], _oper[j]);
				MemoComm->Lines->Add(buff);
			} // for(int j = 0;j < i;j++)
		} // while (i > 1)

		return FloatToStr(_parc[0]);
	} // if(r.Length() > 0)

	return "Expressão vazia!";
} // Calculate
//---------------------------------------------------------------------------

void __fastcall TFormServerDlg::ServerSocketClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
	if(Socket != NULL){
		AnsiString s = Socket->ReceiveText();
		MemoComm->Lines->Add("Solicitação recebida: " + s);
		s = Calculate(s);
		MemoComm->Lines->Add("Enviando resposta: " + s);
		Socket->SendText(s);
	}
}
//---------------------------------------------------------------------------

