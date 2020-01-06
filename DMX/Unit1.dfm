object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DMXColor: TLabel
    Left = 255
    Top = 64
    Width = 109
    Height = 23
    Caption = 'COULEURS'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Algerian'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Bleu: TButton
    Left = 173
    Top = 203
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'Bleu'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = BleuClick
  end
  object Connect: TPanel
    Left = 296
    Top = 24
    Width = 17
    Height = 17
    Color = clRed
    ParentBackground = False
    TabOrder = 1
  end
  object Rouge: TButton
    Left = 352
    Top = 100
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'Rouge'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = RougeClick
  end
  object Vert: TButton
    Left = 173
    Top = 100
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'Vert'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = VertClick
  end
  object Blanc: TButton
    Left = 352
    Top = 203
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'Blanc'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 4
    OnClick = BlancClick
  end
  object ON: TButton
    Left = 174
    Top = 21
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'ON'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Impact'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 5
    OnClick = ONClick
  end
  object Stroboscope: TButton
    Left = 255
    Top = 248
    Width = 114
    Height = 33
    Cursor = crHandPoint
    Caption = 'Stroboscope'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 6
    OnClick = StroboscopeClick
  end
  object Panel1: TPanel
    Left = 433
    Top = 206
    Width = 24
    Height = 18
    Color = clWhite
    ParentBackground = False
    TabOrder = 7
  end
  object PanelBleu: TPanel
    Left = 136
    Top = 206
    Width = 24
    Height = 18
    Color = clBlue
    ParentBackground = False
    TabOrder = 8
  end
  object Panel3: TPanel
    Left = 433
    Top = 103
    Width = 25
    Height = 17
    Color = clRed
    ParentBackground = False
    TabOrder = 9
  end
  object Panel4: TPanel
    Left = 136
    Top = 103
    Width = 25
    Height = 18
    Color = clLime
    ParentBackground = False
    TabOrder = 10
  end
  object OFF: TButton
    Left = 352
    Top = 21
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = 'OFF'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Impact'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 11
    OnClick = OFFClick
  end
  object TrackBar1: TTrackBar
    Left = 232
    Top = 144
    Width = 150
    Height = 45
    TabOrder = 12
  end
  object Timer1: TTimer
    Interval = 40
    OnTimer = Timer1Timer
    Left = 592
    Top = 24
  end
end
