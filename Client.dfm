object FormClientDlg: TFormClientDlg
  Left = 0
  Top = 0
  ActiveControl = EditHostName
  Caption = 'GSURF - Teste de comunica'#231#227'o TCP/IP: Cliente'
  ClientHeight = 332
  ClientWidth = 424
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  DesignSize = (
    424
    332)
  PixelsPerInch = 96
  TextHeight = 13
  object LabelHostName: TLabel
    Left = 16
    Top = 16
    Width = 26
    Height = 13
    Caption = '&Host:'
    FocusControl = EditHostName
  end
  object LabelPortNumber: TLabel
    Left = 199
    Top = 16
    Width = 85
    Height = 13
    Caption = 'N'#250'mero da &porta:'
    FocusControl = EditPortNumber
  end
  object LabelConnectionStatus: TLabel
    Left = 17
    Top = 123
    Width = 97
    Height = 13
    Caption = '<desconectado>'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LabelRequest: TLabel
    Left = 17
    Top = 69
    Width = 167
    Height = 13
    Caption = 'F'#243'rmula a ser enviada ao servidor:'
  end
  object EditHostName: TEdit
    Left = 16
    Top = 35
    Width = 177
    Height = 21
    TabOrder = 0
    Text = '127.0.0.1'
  end
  object EditPortNumber: TEdit
    Left = 199
    Top = 35
    Width = 121
    Height = 21
    Hint = 'Informe o n'#250'mero da porta do servidor a ser usada na comunica'#231#227'o'
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 1
    Text = '175'
  end
  object ButtonConnect: TButton
    Left = 326
    Top = 33
    Width = 75
    Height = 25
    Caption = '&Conectar'
    TabOrder = 2
    OnClick = ButtonConnectClick
  end
  object MemoComm: TMemo
    Left = 17
    Top = 142
    Width = 384
    Height = 169
    Anchors = [akLeft, akTop, akRight, akBottom]
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 3
    WordWrap = False
    ExplicitHeight = 235
  end
  object EditRequestedJob: TEdit
    Left = 17
    Top = 88
    Width = 303
    Height = 21
    Enabled = False
    TabOrder = 4
  end
  object ButtonSend: TButton
    Left = 326
    Top = 86
    Width = 75
    Height = 25
    Caption = '&Enviar'
    Enabled = False
    TabOrder = 5
    OnClick = ButtonSendClick
  end
  object client: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnect = clientConnect
    OnDisconnect = clientDisconnect
    OnRead = clientRead
    OnError = clientError
    Left = 168
    Top = 8
  end
end
