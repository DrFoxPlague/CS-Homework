# CS 232 Lab for Week 13
# Peter Ramos & Dakota Donner

from tkinter import *

class Blow_it_up():
    def __init__(self, parent_window):
        self.frame_1 = Frame(parent_window)
        self.frame_1.grid()
        self.string_out = StringVar()

        # Blow it up button
        self.blow_button = Button(self.frame_1, font=('Times',12))
        self.blow_button.grid(row = 1, column = 4)
        self.blow_button['text'] = "BLOW IT!"
        self.blow_button['command'] = self.blow_it_up

        # labels
        self.title_label = Label(self.frame_1, font=('Times',12))
        self.title_label.grid(row = 1, column = 2)
        self.title_label['text'] = "Enter Text to Blow Up:"

        self.text_in_box = Entry(self.frame_1, fg = 'black', font=('Times',12))
        self.text_in_box.grid(row = 1, column = 3)
        self.text_in_box['width'] = 10

        self.result_label = Label(self.frame_1, fg = "red", font=('Helvetica',50))
        self.result_label.grid(row = 8, column = 2)
        self.result_label['textvariable'] = self.string_out

        # blow_it_up method
    def blow_it_up(self):
        self.text_in = str(self.text_in_box.get())
        self.text_out = (self.text_in)

        self.string_out.set('{0}'.format(self.text_out))

def try_it():
    main_window = Tk()
    main_window.title("Blow Up Text")
    main_window.geometry("500x250")

    x = Blow_it_up(main_window)

    main_window.mainloop()
   
    try:
        main_window.destroy()
    except:
        print("Task ended successfully! :)")

try_it()