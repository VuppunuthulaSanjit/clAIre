"""
clAIre Voice Interaction Module
Handles Speech-to-Text and Emergency Protocols
"""

import speech_recognition as sr
import os

def process_voice():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("clAIre is active. How can I help?")
        audio = recognizer.listen(source)

    try:
        command = recognizer.recognize_google(audio).lower()
        print(f"User said: {command}")

        if "emergency" in command or "help" in command:
            trigger_emergency()
        elif "remind" in command:
            print("Setting medication reminder...")
            
    except sr.UnknownValueError:
        pass

def trigger_emergency():
    # Logic to send alert to the caregiver app and speak via speakers
    os.system("mpg321 emergency_alert.mp3") 
    print("EMERGENCY PROTOCOL: Notifying emergency contacts and local authorities.")

if __name__ == "__main__":
    while True:
        process_voice()
