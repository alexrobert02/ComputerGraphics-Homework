import tkinter as tk

from Pixel import Pixel


class CartesianGrid:
    def __init__(self, master):
        self.master = master
        self.canvas_width = 300
        self.canvas_height = 300
        self.width_pixels = 16

        self.canvas = tk.Canvas(master, width=self.canvas_width, height=self.canvas_height)
        self.canvas.pack()

        self.pixel_size = self.canvas_width // self.width_pixels
        self.height_pixels = self.canvas_height // self.pixel_size
        self.pixels = [[Pixel(j * self.pixel_size + self.pixel_size // 2, i * self.pixel_size + self.pixel_size // 2,
                              self.pixel_size) for j in range(self.width_pixels)] for i in range(self.height_pixels)]

        self.draw()

    def draw(self):
        for row in self.pixels:
            for pixel in row:
                pixel.draw(self.canvas)

    def draw_line(self, x0, y0, x1, y1):

        if abs(y1 - y0) < abs(x1 - x0):
            if x0 > x1:
                self.draw_line_low(x1, y1, x0, y0)
            else:
                self.draw_line_low(x0, y0, x1, y1)
        else:
            if y0 > y1:
                self.draw_line_high(x1, y1, x0, y0)
            else:
                self.draw_line_high(x0, y0, x1, y1)

    def draw_line_high(self, x0, y0, xn, yn):
        self.canvas.create_line(x0 * self.pixel_size + self.pixel_size // 2,
                                y0 * self.pixel_size + self.pixel_size // 2,
                                xn * self.pixel_size + self.pixel_size // 2,
                                yn * self.pixel_size + self.pixel_size // 2, fill="#FF1414", width=2)

        dx = xn - x0
        dy = yn - y0
        xi = 1 if dx > 0 else -1
        dx = abs(dx)
        d = 2 * dx - dy
        x = x0

        for y in range(y0, yn + 1):
            self.pixels[y][x].drawPixel = True
            if d > 0:
                x += xi
                d += 2 * (dx - dy)
            else:
                d += 2 * dx

    def draw_line_low(self, x0, y0, xn, yn):
        self.canvas.create_line(x0 * self.pixel_size + self.pixel_size // 2,
                                y0 * self.pixel_size + self.pixel_size // 2,
                                xn * self.pixel_size + self.pixel_size // 2,
                                yn * self.pixel_size + self.pixel_size // 2,
                                fill="#FF1414", width=2)

        dx = xn - x0
        dy = yn - y0
        yi = 1 if dy > 0 else -1
        dy = abs(dy)
        d = 2 * dy - dx
        y = y0

        for x in range(x0, xn + 1):
            self.pixels[y][x].drawPixel = True
            if d > 0:
                y += yi
                d += 2 * (dy - dx)
            else:
                d += 2 * dy

    def draw_circle(self, ox, oy, r):
        self.canvas.create_oval((ox - r) * self.pixel_size, (self.height_pixels - oy - r) * self.pixel_size,
                                (ox + r) * self.pixel_size, (self.height_pixels - oy + r) * self.pixel_size,
                                outline="#FF1414", width=4)
        x = 0
        y = r

        d = 3 - 2 * r
        dE = 3
        dSE = -2 * r + 5

        while y > x:
            if d < 0:
                d += dE
                dE += 2
                dSE += 2
            else:
                d += dSE
                dE += 2
                dSE += 4
                y -= 1

            x += 1
            self.pixels[oy + x][ox - 1 + y].drawPixel = True
            self.pixels[oy + x][ox - 1 + y + 1].drawPixel = True
            self.pixels[oy + x][ox - 1 + y - 1].drawPixel = True

    # Modified draw_circle method to draw a circle segment
    def draw_circle_segment(self, ox, oy, r):
        x = 0
        y = r

        d = 3 - 2 * r
        dE = 3
        dSE = -2 * r + 5

        while y > x:
            if d < 0:
                d += dE
                dE += 2
                dSE += 2
            else:
                d += dSE
                dE += 2
                dSE += 4
                y -= 1

            x += 1
            self.canvas.create_oval((ox - x) * self.pixel_size, (self.height_pixels - oy - y) * self.pixel_size,
                                    (ox - x + 1) * self.pixel_size, (self.height_pixels - oy - y + 1) * self.pixel_size,
                                    fill="gray25")
            self.canvas.create_oval((ox - y) * self.pixel_size, (self.height_pixels - oy - x) * self.pixel_size,
                                    (ox - y + 1) * self.pixel_size, (self.height_pixels - oy - x + 1) * self.pixel_size,
                                    fill="gray25")
            self.canvas.create_oval((ox + x - 1) * self.pixel_size, (self.height_pixels - oy - y) * self.pixel_size,
                                    (ox + x) * self.pixel_size, (self.height_pixels - oy - y + 1) * self.pixel_size,
                                    fill="gray25")
            self.canvas.create_oval((ox + y - 1) * self.pixel_size, (self.height_pixels - oy - x) * self.pixel_size,
                                    (ox + y) * self.pixel_size, (self.height_pixels - oy - x + 1) * self.pixel_size,
                                    fill="gray25")

    def draw_line_segment(self, x0, y0, x1, y1):
        dx = abs(x1 - x0)
        dy = abs(y1 - y0)

        # Determine the direction of the line
        is_steep = dy > dx

        # Swap the endpoints if the line is steep
        if is_steep:
            x0, y0 = y0, x0
            x1, y1 = y1, x1

        # Swap the endpoints if x1 < x0 to ensure we're always scanning from left to right
        if x1 < x0:
            x0, x1 = x1, x0
            y0, y1 = y1, y0

        # Recalculate differentials after potential swapping
        dx = abs(x1 - x0)
        dy = abs(y1 - y0)
        error = dx // 2
        y_step = 1 if y0 < y1 else -1

        # Keep track of the last drawn pixel
        prev_x = x0
        prev_y = y0

        y = y0
        for x in range(x0, x1 + 1):
            if is_steep:
                self.pixels[x][y].drawPixel = True
                self.canvas.create_oval(y * self.pixel_size, x * self.pixel_size,
                                        y * self.pixel_size + self.pixel_size,
                                        x * self.pixel_size + self.pixel_size, fill="gray25")
            else:
                self.pixels[y][x].drawPixel = True
                self.canvas.create_oval(x * self.pixel_size, y * self.pixel_size,
                                        x * self.pixel_size + self.pixel_size,
                                        y * self.pixel_size + self.pixel_size, fill="gray25")

            error -= dy
            if error < 0:
                y += y_step
                error += dx

            # Ensure pixels are not intersecting
            if prev_x != x and prev_y != y:
                if is_steep:
                    self.pixels[prev_x][prev_y].drawPixel = True
                else:
                    self.pixels[prev_y][prev_x].drawPixel = True

            prev_x = x
            prev_y = y
