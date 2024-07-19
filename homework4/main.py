import tkinter as tk
from CartesianGrid import CartesianGrid


def main():
    root1 = tk.Tk()
    grid1 = CartesianGrid(root1)
    grid1.draw_line(0, 0, 15, 5)
    grid1.draw_line(0, 15, 15, 8)
    grid1.draw_line_segment(0, 0, 15, 5)
    grid1.draw_line_segment(0, 15, 15, 8)

    root2 = tk.Tk()
    grid2 = CartesianGrid(root2)
    grid2.draw_circle(0, 0, 14)
    grid2.draw_circle_segment(0, 0, 14)
    root2.mainloop()


if __name__ == "__main__":
    main()
