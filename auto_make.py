import os
import sys
import time

from watchdog.observers import Observer
from watchdog.events import PatternMatchingEventHandler


class AutoMake(PatternMatchingEventHandler):
    patterns = ["*.h", "*.cpp"]

    def process(self, event):
        os.system('make osx')

    def on_modified(self, event):
        self.process(event)


if __name__ == '__main__':
    print sys.argv
    args = sys.argv[1:]
    observer = Observer()
    observer.schedule(AutoMake(), path=args[0] if args else '.')
    observer.start()

    try:
        while True:
            time.sleep(2)
    except KeyboardInterrupt:
        observer.stop()

    observer.join()
