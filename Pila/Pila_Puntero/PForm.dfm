object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 442
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 24
    Width = 105
    Height = 25
    Caption = 'Crear_Pila'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 64
    Width = 105
    Height = 25
    Caption = 'Poner_Pila'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 104
    Width = 105
    Height = 25
    Caption = 'Mostrar_Pila'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 400
    Width = 81
    Height = 25
    Caption = 'Salir'
    TabOrder = 3
    OnClick = Button4Click
  end
end
