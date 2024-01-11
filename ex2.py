# Implementation 1
class Fifo:
    def __init__(self):
        self.content = []

    def add(self, element):
        self.content.append(element)

    def remove(self):
        self.content.pop(0)

    def get(self):
        return self.content
    
# Implementation 2
class Lifo:
    def __init__(self):
        pass

    def add(self, element):
        pass

    def remove(self):
        pass

    def get(self):
        pass