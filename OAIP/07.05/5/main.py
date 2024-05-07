from tkinter import Tk as Window, Button, Entry, StringVar

def set_geometry(target: Entry, width: StringVar, height: StringVar):
    target.config(width=int(width.get()))
    

def main():
    main_window = Window()
    main_window.title("Задача №5")
    main_window.geometry('300x200')

    height = StringVar()
    width = StringVar()
    height_entry = Entry(main_window, textvariable=height)
    width_entry = Entry(main_window, textvariable=width)
    big_entry = Entry(main_window)
    submit_btn = Button(main_window, text="submit", command=lambda: set_geometry(big_entry, width, height))

    submit_btn.pack()
    height_entry.pack()
    width_entry.pack()
    big_entry.pack(expand=True)

    main_window.mainloop()


if __name__ == "__main__":
    main()
