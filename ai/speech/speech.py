#!/usr/bin/python

import speech_recognition as sr
import pyttsx3
import pywhatkit
import datetime
import wikipedia
import pyjokes

listener = sr.Recognizer()
engine = pyttsx3.init()
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)

def talk(text):
	engine.say(text)
	engine.runAndWait()

def take_command():
	try:
		with sr.Microphone() as source:
			print('Listening...');
			voice = listener.listen(source)
			command = listener.recognize_google(voice)
			command = command.lower()
			if 'model' in command:
				command = command.replace('model', '')
# 				print(command)
	except:
		pass
	return command
