from dotenv import load_dotenv, dotenv_values
from openai import OpenAI
import sys
import os

class Client:

    def __init__(self):
        load_dotenv()
        self.__key = os.getenv("GPT_API")
        self.basePrompt = """You are JARVIS - AI assistant created to help with a different tasks.
                        Your answers should be short, but it should understand common user of the topic.
                        Try to analize user questions to understand with what problems user have often problems. Mark them with one key word on the start of the unswer and on with seccond in the end.
                        If user will ask you to do some dificult tasks (like coding, analizing heavy documents a.t.c) - say that you can't do it.
                        Your answers should also be like JARVIS from the Iron Man move.
                        You need to use maximum 500 tokens"""
        self.client = OpenAI(api_key=self.__key)
    
    # Returns result from the model
    # Using gpt-5-mini model
    def request(self, request: str) -> str:
        try:
            stream = self.client.responses.create(
                model="gpt-5-mini",
                max_output_tokens= 500,
                reasoning={"effort": "low"},
                input=[
                    {
                        "role": "developer",
                        "content": self.basePrompt
                    },
                    {
                        "role": "user",
                        "content": request
                    }
                ],
                stream=True
            )
            for event in stream:
                if event.type == "response.output_text.delta":
                    sys.stdout.write(event.delta)
                    sys.stdout.flush()
        except:
            print("There was problem with gpt")

    def updatePrompt(self, newPrompt: str) -> None:
        if newPrompt == '' or not newPrompt.isspace():
            self.prompt = newPrompt
