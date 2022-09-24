#!/usr/bin/python

import sys, getopt

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

def main(argv):
   inputfile = ''
   outputfile = ''
   print('Nr. of arguments:', len(sys.argv))
   print('Arguments:', str(sys.argv))
   try:
      opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
   except getopt.GetoptError:
      print('test.py -i <inputfile> -o <outputfile>')
      sys.exit(2)
   for opt, arg in opts:
      if opt == '-h':
         print('test.py -i <inputfile> -o <outputfile>')
         sys.exit()
      elif opt in ("-i", "--ifile"):
         inputfile = arg
      elif opt in ("-o", "--ofile"):
         outputfile = arg
   print('Input file is "', inputfile)
   print('Output file is "', outputfile)

if __name__ == "__main__":
   main(sys.argv[1:])