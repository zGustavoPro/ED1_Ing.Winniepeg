object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 540
  ClientWidth = 867
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 32
    Top = 88
    Width = 97
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 144
    Width = 97
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 32
    Top = 200
    Width = 97
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 32
    Top = 264
    Width = 97
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 32
    Top = 320
    Width = 97
    Height = 25
    Caption = 'Poner dato'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 176
    Top = 144
    Width = 121
    Height = 23
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 176
    Top = 201
    Width = 121
    Height = 23
    TabOrder = 6
  end
  object Edit3: TEdit
    Left = 176
    Top = 265
    Width = 73
    Height = 23
    TabOrder = 7
  end
  object Edit4: TEdit
    Left = 272
    Top = 265
    Width = 73
    Height = 23
    TabOrder = 8
  end
  object Edit5: TEdit
    Left = 176
    Top = 321
    Width = 73
    Height = 23
    TabOrder = 9
  end
  object Edit6: TEdit
    Left = 272
    Top = 321
    Width = 73
    Height = 23
    TabOrder = 10
  end
  object Edit7: TEdit
    Left = 368
    Top = 321
    Width = 65
    Height = 23
    TabOrder = 11
  end
  object Button6: TButton
    Left = 32
    Top = 368
    Width = 97
    Height = 25
    Caption = 'Suma'
    TabOrder = 12
    OnClick = Button6Click
  end
  object Edit8: TEdit
    Left = 176
    Top = 369
    Width = 73
    Height = 23
    TabOrder = 13
  end
  object Edit9: TEdit
    Left = 272
    Top = 369
    Width = 73
    Height = 23
    TabOrder = 14
  end
  object Button7: TButton
    Left = 8
    Top = 507
    Width = 75
    Height = 25
    Caption = 'Salir'
    TabOrder = 15
    OnClick = Button7Click
  end
end
