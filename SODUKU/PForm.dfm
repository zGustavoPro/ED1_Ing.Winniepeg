object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 513
  ClientWidth = 852
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  OnKeyDown = FormKeyDown
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 16
    Width = 105
    Height = 25
    Caption = 'Crear_Memoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 47
    Width = 105
    Height = 25
    Caption = 'Pedir_Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 78
    Width = 105
    Height = 25
    Caption = 'Liberar_Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 133
    Width = 105
    Height = 25
    Caption = 'Crear_Matriz_D'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 164
    Width = 105
    Height = 25
    Caption = 'Definir_ValorRep'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 195
    Width = 105
    Height = 25
    Caption = 'Dimensionar_Mat'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 226
    Width = 105
    Height = 25
    Caption = 'Poner'
    TabOrder = 6
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 8
    Top = 281
    Width = 105
    Height = 25
    Caption = 'Mostrar_Matriz'
    TabOrder = 7
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 8
    Top = 312
    Width = 105
    Height = 25
    Caption = 'Mostrar_Memoria'
    TabOrder = 8
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 8
    Top = 343
    Width = 105
    Height = 25
    Caption = 'Verificar_Sudoku'
    TabOrder = 9
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 8
    Top = 374
    Width = 105
    Height = 25
    Caption = 'Retroceder_Poner'
    TabOrder = 10
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 8
    Top = 470
    Width = 75
    Height = 25
    Caption = 'Salir'
    TabOrder = 11
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 8
    Top = 405
    Width = 105
    Height = 25
    Caption = 'BackTracking'
    TabOrder = 12
    OnClick = Button13Click
  end
end
