import neko
import time

class StartScene(neko.NekoScene):
    def onQuit():
        global running
        print "Quit it!"
        running = False

engine = neko.NekoInstance()
running = True
scene = neko.NekoScene(640, 480, "test");
engine.loadScene(scene)

