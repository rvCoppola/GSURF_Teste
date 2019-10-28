object FormServerDlg: TFormServerDlg
  Left = 0
  Top = 0
  Caption = 'GSURF - Teste de comunica'#231#227'o TCP/IP: Servidor'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    635
    299)
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonActivate: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = '&Ativar'
    TabOrder = 0
    OnClick = ButtonActivateClick
  end
  object MemoComm: TMemo
    Left = 8
    Top = 48
    Width = 619
    Height = 243
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 1
  end
  object ServerSocket: TServerSocket
    Active = False
    Port = 175
    ServerType = stNonBlocking
    OnClientConnect = ServerSocketClientConnect
    OnClientDisconnect = ServerSocketClientDisconnect
    OnClientRead = ServerSocketClientRead
    Left = 248
  end
end
