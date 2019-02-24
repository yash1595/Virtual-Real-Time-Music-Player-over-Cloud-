'''
@File: leapSensorPiano.py

@References: https://www.youtube.com/watch?v=T9k7rdY625M

@Dependencies: Leap.py, Leap.dll, Leap.lib, LeapPython.pyd

@Description: This is a python script that read leap motion sensor gesture data and writes it onto a serial
              terminal. Devices can read this data from the serial terminal and process it accordindly.


@Note: This code works with Python 2.7 and is not compatible with Python 3 or above. To run the code on 
       windows, type: py -2 .\leapSensorPiano.py on the cmd.

'''



#!python2
import Leap, sys, thread, time, serial
from Leap import CircleGesture, KeyTapGesture, ScreenTapGesture, SwipeGesture

serialTerm = serial.Serial('COM15', 115200) # Defines serial port of subscribing device


index = 0 
prevFingerCount = 0 # Stores previous finger count 
fingerCount = 0 # Stores current finger count

''' Class called for leap motion sensor events '''
class LeapMotionListener(Leap.Listener):
    finger_names = ['Thumb', 'Index', 'Middle', 'Ring', 'Pinky']

    ''' Function called on Initialization '''
    def on_init(self, controller):
        print "Initialized"

    ''' Function called when leap motion sensor gets connected '''
    def on_connect(self, controller):
        print "Motion sensor connected"

        controller.enable_gesture(Leap.Gesture.TYPE_CIRCLE);
        controller.enable_gesture(Leap.Gesture.TYPE_KEY_TAP);
        controller.enable_gesture(Leap.Gesture.TYPE_SCREEN_TAP);
        controller.enable_gesture(Leap.Gesture.TYPE_SWIPE);

    ''' Function called when leap motion sensor gets disconnected '''
    def on_disconnect(self, controller):
        print "Motion sensor disconnected"

    ''' Function called on force exit '''
    def on_exit(self, controller):
        print "Exited"

    ''' Function called when leap motion data is available '''
    def on_frame(self, controller):
        frame = controller.frame() # Contains the hand, finger and bone data
        global index
        global prevFingerCount
        global fingerCount
        for finger in frame.fingers.extended(): # Loop to iterate over finger data
            index+=1
            if(index%20 == 0): # Added delay for accurrate mesuarement of finger data
                index = 0
                if(fingerCount == 1):  
                    serialTerm.write("s")
                elif(fingerCount == 2):
                    serialTerm.write("a")
                elif(fingerCount == 3):
                    serialTerm.write("b")

                finalCount = fingerCount
                fingerCount = 0
                prevFingerCount = 0
                time.sleep(1)
            fingerCount = max(finger.type , prevFingerCount)
            prevFingerCount = fingerCount


''' Main function to listen to leap motion events ''' 
def main():
    listener = LeapMotionListener()
    controller = Leap.Controller()

    controller.add_listener(listener)

    print "Press enter to exit"

    try:
        sys.stdin.readline()
    except KeyboardInterrupt:
        pass

    finally:
        controller.remove_listener(listener)


if __name__ == "__main__":
    main()