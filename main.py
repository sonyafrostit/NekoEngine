import neko
import time
engine = neko.NekoInstance()
class StartScene(neko.NekoScene):
    def onQuit():
        print "Quit it!"
        engine.stop()
scene = StartScene(640, 480, "test");
engine.loadScene(scene)
engine.start()
