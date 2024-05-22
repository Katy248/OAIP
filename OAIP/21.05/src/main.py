from random import random
import sys, gi
gi.require_version('Gtk', '4.0')
gi.require_version('Adw', '1')
from gi.repository import  Gtk, Adw




class GameWindow(Adw.ApplicationWindow):
    def __init__(self,  *args, **kwargs):
        super().__init__(*args, **kwargs)
        
        view = Adw.ToolbarView()
        view.set_content(self.get_content())
        header_bar = Adw.HeaderBar()
        header_bar.set_title_widget(Adw.WindowTitle(title= "Sea Battle", subtitle="Shout them all"))
        view.add_top_bar(header_bar)
        self.set_content(view)
        self.set_size_request(500, 1000)

    def get_content(self) -> Gtk.Widget:
        
        field = FieldBox()
        clamp = Adw.Clamp()
        clamp.set_margin_top(12)
        clamp.set_margin_bottom(12)
        clamp.set_margin_start(12)
        clamp.set_margin_end(12)
        clamp.set_child(field)
        return clamp
    

class FieldBox(Gtk.Box):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

        give_up_btn = Gtk.Button()
        give_up_btn.set_label("Give up")
        give_up_btn.add_css_class("pill")
        give_up_btn.add_css_class("destructive-action")

        btn = Gtk.Button()
        btn.set_label("Press me")
        btn.add_css_class("pill")
        btn.add_css_class("suggested-action")

        field_box = Gtk.Box()
        field_box.set_orientation(Gtk.Orientation.VERTICAL)
        field_box.set_spacing(12)
        field_box.set_halign(Gtk.Align.CENTER)
        
        first_line = Gtk.Box()
        first_line.set_orientation(Gtk.Orientation.HORIZONTAL)
        first_line.set_spacing(12)


        CHARS = "АБВГДЕЖЗИК"
        for i in range(11):
            number_label = Gtk.Button()
            if i > 0:
                number_label.set_label(f"{CHARS[i-1]}")
                number_label.add_css_class("accent")
            else:
                number_label.set_child(Gtk.Image(icon_name="map-symbolic"))
            number_label.add_css_class("circular")
            # number_label.add_css_class("flat")
            first_line.append(number_label)
        field_box.append(first_line)

        for i in range(10):
            line_box = Gtk.Box()
            line_box.set_orientation(Gtk.Orientation.HORIZONTAL)
            line_box.set_spacing(12)

            number_label = Gtk.Button()
            number_label.set_label(f"{i + 1}")
            number_label.add_css_class("accent")
            number_label.add_css_class("circular")
            # number_label.add_css_class("flat")

            line_box.append(number_label)
            for j in range(10):
                cell_btn = Gtk.Button()
                cell_btn.add_css_class("circular")
                cell_btn.connect('clicked', lambda btn: self.check_cell_btn(btn, i, j))

                line_box.append(cell_btn)
            field_box.append(line_box)

        self.set_spacing(32)
        self.set_orientation(Gtk.Orientation.VERTICAL)
        self.append(field_box)
        self.append(btn)
        self.append(give_up_btn)
    def check_cell_btn(self, btn: Gtk.Button, i: int, j: int):

        if random() < 0.8:
            # btn.set_child(Gtk.Image(icon_name="fcitx-fullwidth-inactive-symbolic"))
            btn.add_css_class("destructive-action")
        else:
            btn.set_child(Gtk.Image(icon_name="emblem-ok-symbolic"))
            btn.add_css_class("suggested-action")

class MenuWindow(Adw.ApplicationWindow):
    def __init__(self,  *args, **kwargs):
        super().__init__(*args, **kwargs)
        
        view = Adw.ToolbarView()
        view.set_content(self.get_content())
        header_bar = Adw.HeaderBar()
        header_bar.set_title_widget(Adw.WindowTitle(title= "Sea Battle", subtitle="Main menu"))
        view.add_top_bar(header_bar)
        self.set_content(view)
        self.set_size_request(500, 1000)

    def get_content(self) -> Gtk.Widget:
        
        title = Gtk.Label()
        title.set_label("Sea Battle")
        title.add_css_class("title-1")

        host_btn = Gtk.Button()
        host_btn.set_label("Host game")
        host_btn.add_css_class("pill")
        host_btn.add_css_class("suggested-action")

        connect_btn = Gtk.Button()
        connect_btn.set_label("Connect to game")
        connect_btn.add_css_class("pill")
        connect_btn.add_css_class("suggested-action")

        box = Gtk.Box()
        box.set_orientation(Gtk.Orientation.VERTICAL)
        box.set_spacing(32)
        box.set_valign(Gtk.Align.CENTER)

        box.append(title)
        box.append(host_btn)
        box.append(connect_btn)

        clamp = Adw.Clamp()
        clamp.set_margin_top(12)
        clamp.set_margin_bottom(12)
        clamp.set_margin_start(12)
        clamp.set_margin_end(12)
        clamp.set_child(box)
        return clamp
        

class MyApp(Adw.Application):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        self.connect('activate', self.on_activate)

    def on_activate(self, app):
        self.win = MenuWindow(application=app)
        self.win.present()

if __name__ == "__main__":
    app = MyApp(application_id="ru.Katy248.SeaBattle")
    app.run(sys.argv)
