import sys
import os

# шлях до core/build
current_dir = os.path.dirname(__file__)
core_path = os.path.abspath(os.path.join(current_dir, "../core/build"))

sys.path.append(core_path)

import worker

from llm.client import Client

w = worker.Worker()

def detect(с: Client, text: str):
    if text == 'Hi':
        print('Hi, how are you?')
    else:
        с.request(text)
        print('\n')


def __main__():
    line: str
    c = Client()
    while(True):
        line = input('You: ')
        if line == 'exit':
            break
        res = w.detectFromText(line)
        if(res == 'None'):
            detect(c, line)
        else:
            print(res)

__main__()