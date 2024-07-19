class Pixel:
    def __init__(self, x, y, pixel_size):
        self.drawPixel = False
        self.x = x
        self.y = y
        self.pixel_size = pixel_size

    def draw(self, canvas):
        canvas.create_line(self.x, self.y - self.pixel_size // 2, self.x, self.y + self.pixel_size // 2, fill="gray25")
        canvas.create_line(self.x - self.pixel_size // 2, self.y, self.x + self.pixel_size // 2, self.y, fill="gray25")
        if self.drawPixel:
            canvas.create_oval(self.x - self.pixel_size // 2, self.y - self.pixel_size // 2, self.x + self.pixel_size // 2, self.y + self.pixel_size // 2, fill="#1E1E1E")
