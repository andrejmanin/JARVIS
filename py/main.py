from llm.client import Client
from dotenv import load_dotenv, dotenv_values
import os
from openai import OpenAI


# load_dotenv()

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
        detect(c, line) # Call C++ part

__main__()

# There are some tasks for today:
# Firstly, connect GPT API to the project and test some kind of situations
# Secondly, add Engine class in the core part (C++) and connect it with py-part using "pybind11"
# After that all, you can add STT and TTS.