object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 433
  ClientWidth = 622
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 216
    Top = 8
    Width = 147
    Height = 41
    Caption = 'Proyecto 3'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -30
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Button1: TButton
    Left = 32
    Top = 104
    Width = 75
    Height = 25
    Caption = 'Crear'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 154
    Width = 75
    Height = 25
    Caption = 'primero'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 32
    Top = 201
    Width = 75
    Height = 25
    Caption = 'fin'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 32
    Top = 248
    Width = 75
    Height = 25
    Caption = 'mostrar'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 144
    Top = 155
    Width = 121
    Height = 23
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 144
    Top = 202
    Width = 121
    Height = 23
    TabOrder = 5
  end
  object Button5: TButton
    Left = 8
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Salir'
    TabOrder = 6
    OnClick = Button5Click
  end
end
