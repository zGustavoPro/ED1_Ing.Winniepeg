object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 655
  ClientWidth = 1018
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 121
    Height = 25
    Caption = 'Inicializar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 135
    Top = 8
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object Button2: TButton
    Left = 8
    Top = 39
    Width = 121
    Height = 25
    Caption = 'activar fantasmas'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 96
    Width = 121
    Height = 25
    Caption = 'Iniciar Pacman'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 121
    Top = 368
    Width = 75
    Height = 25
    Caption = 'Arriba'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 40
    Top = 401
    Width = 75
    Height = 25
    Caption = 'Izquierda'
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 216
    Top = 401
    Width = 75
    Height = 25
    Caption = 'Derecha'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 121
    Top = 432
    Width = 75
    Height = 25
    Caption = 'Abajo'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 8
    Top = 560
    Width = 107
    Height = 25
    Caption = 'Salir'
    TabOrder = 8
    OnClick = Button8Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 936
    Top = 24
  end
end
