import serial                                                                   # Serial library for UART communication
from serial import Serial
from playsound import playsound                                                 # Audio library for playing back music notes


COM_PORT = 'COM15'                                                              # COM PORT for the Photon board
SONG_LIST=[]                                                                    # Empty array for adding the recorded tunes


ser=serial.Serial(COM_PORT,115200,timeout=1)                                    # Selecting the baud and timeout for the connection
Notes=['note1\n','note2\n','note3\n','note4\n','note5\n','note6\n','note7\n','note8\n']
Tunes=['do.wav','re.wav','mi.wav','fa.wav','so.wav','la.wav','re.wav','do.wav'] # predefined Notes and Tunes
START = 0


while True:                                                                     
    ser.close()                                                                 # Closing the serial port to refresh it
    ser=serial.Serial(COM_PORT,115200,timeout=1)                                # Setting up the serial and baud again
    key = ser.readline().decode('utf-8')                                        # Reading the incoming serial data
    print(key)
    if(key == 'leap_commands'):                                                 # Command to start recording
        START=1
        playsound('start.wav')                                                  # Play back of the 'Start' command
    elif(key == 'leap_commanda'):                                               # Command to stop recording
        START=0
        playsound('stop.wav')                                                   # Play back of the 'Stop' command
    elif(key == 'leap_commandb'):                                               # Command to Play-back the recording
        playsound('play.wav')                                                   # Play back of the 'Play' command
        try:
            for i in SONG_LIST:                                                 # Play-back each note of the recorded tunes
                playsound(i)
            del SONG_LIST[:]                                                    # Empty the song list to record new data
        except:
            print(" ")                                                          # If list is empty, print a space
    
    for i in range(0,8):                                                        # Scanning through the list to search for the played note
        if(key == Notes[i]):
            playsound(Tunes[i])
            if(START):                                                          # If a start command had been issued, incoming tunes are
                SONG_LIST.append(Tunes[i])                                      # are played back
            break;
    
    
            


        
        


