object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 222
  ClientWidth = 319
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 80
    Top = 24
    Width = 163
    Height = 28
    Caption = 'Menur(Opciones)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 104
    Top = 72
    Width = 97
    Height = 25
    Caption = 'Guardar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 104
    Top = 103
    Width = 97
    Height = 25
    Caption = 'Reiciar'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 104
    Top = 165
    Width = 97
    Height = 25
    Caption = 'Salir'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 104
    Top = 134
    Width = 97
    Height = 25
    Caption = 'Volver'
    TabOrder = 3
    OnClick = Button4Click
  end
end
