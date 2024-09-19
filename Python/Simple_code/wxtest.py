import wx

class MyFrame(wx.Frame):
    def __init__(self):
        super().__init__(None, title='EARMOD', size=(400, 400))
        self.Bind(wx.EVT_PAINT, self.on_paint)
        self.Bind(wx.EVT_TIMER, self.on_timer)
        self.timer = wx.Timer(self)
        self.timer.Start(50)  # Rafraîchissement toutes les 50 millisecondes
        self.offset = -400
        self.message = "AERMOD TRAITEMENT"

    def on_paint(self, event):
        dc = wx.PaintDC(self)
        dc.Clear()
        dc.SetTextForeground(wx.BLACK)
        dc.DrawText(self.message, self.offset, 200)

    def on_timer(self, event):
        self.offset += 5  # Déplacer le texte de 5 pixels vers la droite
        if self.offset > self.GetSize().width:
            self.offset = -400  # Réinitialiser la position du texte à gauche de la fenêtre
        self.Refresh()

if __name__ == '__main__':
    app = wx.App()
    frame = MyFrame()
    frame.Show()
    app.MainLoop()