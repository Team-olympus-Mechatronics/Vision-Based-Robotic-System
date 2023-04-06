import cv2 as cv
import numpy as np
cap = cv.VideoCapture(0)
while(1):
    # Take each frame
    _, frame = cap.read()
    # Convert BGR to HSV
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)
    # define range of blue color in HSV
    # lower_blue = np.array([110,50,50])
    # upper_blue = np.array([130,255,255])
    
    #Define range of red color in HSV
    lower_blue = np.array([0,100,40])
    upper_blue = np.array([20,255,255])
    # Threshold the HSV image to get only blue colors
    mask = cv.inRange(hsv, lower_blue, upper_blue)
    edged = cv.Canny(hsv, 30, 200)
    contours, hierarchy = cv.findContours(edged, 
    cv.RETR_EXTERNAL, cv.CHAIN_APPROX_NONE)
  
    cv.imshow('Canny Edges After Contouring', edged)
    cv.waitKey(0)
  
    print("Number of Contours found = " + str(len(contours)))
  
# Draw all contours
# -1 signifies drawing all contours
    cv.drawContours(frame, contours, -1, (0, 255, 0), 3)
    
    # Bitwise-AND mask and original image
    res = cv.bitwise_and(frame,frame, mask= mask)
    cv.imshow('frame',frame)
    cv.imshow('mask',mask)
    cv.imshow('res',res)
    cv.imshow('Contours', frame)
    k = cv.waitKey(5) & 0xFF
    if k == 27:
        break
cv.destroyAllWindows()