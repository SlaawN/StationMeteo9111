object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 243
  ClientWidth = 527
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object INITIALISATION: TButton
    Left = 24
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Temperature'
    TabOrder = 0
    OnClick = INITIALISATIONClick
  end
  object RAZ: TButton
    Left = 169
    Top = 24
    Width = 75
    Height = 25
    Caption = 'RAZ'
    TabOrder = 1
    OnClick = RAZClick
  end
  object Sortie_10V: TButton
    Left = 280
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Sortie_10V'
    TabOrder = 2
    OnClick = Sortie_10VClick
  end
  object Sortie_5V: TButton
    Left = 424
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Sortie_5V'
    TabOrder = 3
    OnClick = Sortie_5VClick
  end
  object Sortie_0V: TButton
    Left = 96
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Sortie_0V'
    TabOrder = 4
    OnClick = Sortie_0VClick
  end
  object Affichage: TButton
    Left = 352
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Affichage'
    TabOrder = 5
    OnClick = AffichageClick
  end
end
