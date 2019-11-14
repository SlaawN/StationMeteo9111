object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 358
  ClientWidth = 687
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Connecté: TLabel
    Left = 8
    Top = 337
    Width = 46
    Height = 13
    Caption = 'Connect'#233
  end
  object BtnReceive: TButton
    Left = 8
    Top = 151
    Width = 75
    Height = 25
    Caption = 'Recevoir'
    TabOrder = 0
    Visible = False
    OnClick = BtnReceiveClick
  end
  object BtnConnect: TButton
    Left = 8
    Top = 56
    Width = 75
    Height = 25
    Caption = 'Connexion'
    TabOrder = 1
    OnClick = BtnConnectClick
  end
  object MemoRecu: TMemo
    Left = 129
    Top = 7
    Width = 288
    Height = 343
    TabOrder = 2
    OnChange = MemoRecuChange
  end
  object PanelConnect: TPanel
    Left = 60
    Top = 337
    Width = 13
    Height = 13
    Color = clRed
    ParentBackground = False
    TabOrder = 3
  end
  object MemoTri: TMemo
    Left = 504
    Top = 8
    Width = 175
    Height = 342
    TabOrder = 4
  end
  object BtnDeconnect: TButton
    Left = 8
    Top = 240
    Width = 75
    Height = 25
    Caption = 'Deconnexion'
    TabOrder = 5
    Visible = False
    OnClick = BtnDeconnectClick
  end
end
