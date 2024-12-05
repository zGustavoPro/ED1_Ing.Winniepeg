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
    Left = 24
    Top = 66
    Width = 121
    Height = 25
    Caption = 'Crear_Polinomio'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 24
    Top = 105
    Width = 121
    Height = 25
    Caption = 'Poner_Termino'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 24
    Top = 152
    Width = 121
    Height = 25
    Caption = 'Mostrar_Polinomio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 24
    Top = 200
    Width = 121
    Height = 25
    Caption = 'Derivar'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 409
    Width = 73
    Height = 25
    Caption = 'Salir'
    TabOrder = 4
    OnClick = Button5Click
  end
end
