object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 352
  ClientWidth = 683
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 9
    Top = 27
    Width = 136
    Height = 13
    Caption = 'Temperature actuelle en '#176'C:'
  end
  object LblTemp: TLabel
    Left = 151
    Top = 27
    Width = 3
    Height = 13
  end
  object LblCommande: TLabel
    Left = 56
    Top = 72
    Width = 182
    Height = 13
    Caption = 'Choisissez le pourcentage de chauffe '
  end
  object LblCommandeTemp: TLabel
    Left = 56
    Top = 109
    Width = 140
    Height = 13
    Caption = 'Temp'#233'rature d'#233'sir'#233'e en '#176'C : '
  end
  object ListTemp: TComboBox
    Left = 258
    Top = 69
    Width = 40
    Height = 21
    TabOrder = 0
    Text = '0'
    OnChange = ListTempChange
    Items.Strings = (
      '0'
      '25'
      '50'
      '75'
      '100')
  end
  object BtnInitisialisation: TButton
    Left = 248
    Top = 159
    Width = 165
    Height = 25
    Caption = 'CONNEXION'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Algerian'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = BtnInitisialisationClick
  end
  object EdtTemp: TEdit
    Left = 237
    Top = 106
    Width = 59
    Height = 21
    NumbersOnly = True
    TabOrder = 2
    Text = '50'
    OnChange = EdtTempChange
  end
  object BtnStart: TButton
    Left = 339
    Top = 104
    Width = 136
    Height = 25
    Caption = 'Lancer Four'
    TabOrder = 3
    OnClick = BtnStartClick
  end
  object BtnStop: TButton
    Left = 481
    Top = 104
    Width = 128
    Height = 25
    Caption = 'Arreter Four'
    TabOrder = 4
    OnClick = BtnStopClick
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 65520
    Top = 352
  end
  object Timer2: TTimer
    Enabled = False
    OnTimer = Timer2Timer
    Left = 680
    Top = 344
  end
end
