object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 505
  ClientWidth = 915
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 90
    Height = 25
    Caption = 'CrearMemoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 39
    Width = 90
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 70
    Width = 89
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 8
    Top = 101
    Width = 105
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 3
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 460
    Width = 75
    Height = 25
    Caption = 'Salir'
    TabOrder = 4
    OnClick = Button6Click
  end
  object Button8: TButton
    Left = 8
    Top = 214
    Width = 75
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 5
    OnClick = Button8Click
  end
  object Button10: TButton
    Left = 8
    Top = 245
    Width = 90
    Height = 25
    Caption = 'Inserta Primero'
    TabOrder = 6
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 8
    Top = 286
    Width = 89
    Height = 25
    Caption = 'Inserta Ultimo'
    TabOrder = 7
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 8
    Top = 317
    Width = 75
    Height = 25
    Caption = 'Mostrar Lista'
    TabOrder = 8
    OnClick = Button12Click
  end
end
