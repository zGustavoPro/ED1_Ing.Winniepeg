object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 360
  ClientWidth = 919
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 56
    Width = 113
    Height = 25
    Caption = 'Crear_Polinomio'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 104
    Width = 113
    Height = 25
    Caption = 'Poner_Termino'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 144
    Width = 113
    Height = 25
    Caption = 'Mostrar_Polinomio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 184
    Width = 113
    Height = 25
    Caption = 'Derivar'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 310
    Width = 75
    Height = 25
    Caption = 'Salir'
    TabOrder = 4
    OnClick = Button5Click
  end
end
